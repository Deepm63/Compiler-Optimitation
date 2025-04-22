import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import classification_report, accuracy_score
import pickle

# === Load and merge ===
benchmark_files = [
    "benchmark_results1.csv",
    "benchmark_results2.csv",
    "benchmark_results3.csv",
    "benchmark_results4.csv",
    "benchmark_results5.csv"
]
benchmark_df = pd.concat([pd.read_csv(f) for f in benchmark_files], ignore_index=True)
features_df = pd.read_csv("loop_features.csv")
merged_df = pd.merge(benchmark_df, features_df, left_on="loop_id", right_on="dag_id")

# === Construct 36-class label (tile + loop combo) ===
merged_df["combo_label"] = merged_df["tile_size"].astype(str) + "_" + merged_df["loop_order"]

# Create class label encoder
label_encoder = LabelEncoder()
merged_df["combo_class"] = label_encoder.fit_transform(merged_df["combo_label"])
combo_labels = label_encoder.classes_

# === Prepare features and target ===
X = merged_df.drop(columns=["exec_time_ms", "loop_id", "dag_id", "tile_size", "loop_order", "combo_label"])
y = merged_df["combo_class"]

# === Subsample to speed up ===
sampled_df = merged_df.sample(n=50000, random_state=42)
X_sample = sampled_df[X.columns]
y_sample = sampled_df["combo_class"]

# === Split train/test ===
X_train, X_test, y_train, y_test = train_test_split(X_sample, y_sample, test_size=0.2, random_state=42)

# === Train classifier ===
clf = RandomForestClassifier(n_estimators=200, max_depth=25, random_state=42, class_weight="balanced")
clf.fit(X_train, y_train)

# === Evaluate ===
y_pred = clf.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)
print(f"✅ Classification Accuracy (36-class): {accuracy:.4f}\n")

print("📊 Classification Report (tile_size + loop_order):")
print(classification_report(y_test, y_pred, target_names=combo_labels, zero_division=0))

with open("model_features.txt", "w") as f:
    for col in X.columns:
        f.write(col + "\n")

# Save LabelEncoder (used for combo_class)
with open("label_encoder.pkl", "wb") as f:
    pickle.dump(label_encoder, f)

# Save trained classifier (RandomForestClassifier or other)
with open("trained_classifier.pkl", "wb") as f:
    pickle.dump(clf, f)
