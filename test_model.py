import pandas as pd
import pickle
from sklearn.metrics import classification_report, accuracy_score

# === Load test benchmark and features ===
test_df = pd.read_csv("test_benchmark_results.csv")          # Your test loops (100 rows)
features_df = pd.read_csv("test_combined_features.csv")       # Same features file used in training

# === Merge on loop_id ↔ dag_id (same as training) ===
merged_test = pd.merge(test_df, features_df, left_on="loop_id", right_on="dag_id")

# === Reconstruct combo label (e.g., 32_L5) and encode class ===
merged_test["combo_label"] = merged_test["tile_size"].astype(str) + "_" + merged_test["loop_order"]

# === Load label encoder and classifier ===
with open("label_encoder.pkl", "rb") as f:
    label_encoder = pickle.load(f)

with open("trained_classifier.pkl", "rb") as f:
    clf = pickle.load(f)

# Encode target combo class
merged_test["combo_class"] = label_encoder.transform(merged_test["combo_label"])

# === Load feature list used during training ===
with open("model_features.txt", "r") as f:
    feature_list = [line.strip() for line in f.readlines()]

# Select same columns (exact order)
X_test = merged_test[feature_list]
y_test = merged_test["combo_class"]

# === Predict and evaluate ===
y_pred = clf.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)
print(f"✅ Accuracy on Test Dataset: {accuracy:.4f}\n")

print("📊 Classification Report:")
print(classification_report(
    y_test,
    y_pred,
    target_names=label_encoder.classes_,
    zero_division=0
))
