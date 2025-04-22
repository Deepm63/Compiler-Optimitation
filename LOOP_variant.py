# variant_generator.py - generate 36 tiled variants per loop file
import os
import re

INPUT_DIR = "generated_loops"
OUTPUT_DIR = "loop_variants/Batch1"
# BATCH = "Batch1"
os.makedirs(OUTPUT_DIR, exist_ok=True)

tile_sizes = [8, 16, 32, 64, 128, 256]
loop_orders = {
    "L1": ["i", "j", "ii", "jj"],
    "L2": ["i", "j", "jj", "ii"],
    "L3": ["i", "ii", "j", "jj"],
    "L4": ["j", "i", "ii", "jj"],
    "L5": ["j", "i", "jj", "ii"],
    "L6": ["j", "jj", "i", "ii"]
}

loop_files = sorted([f for f in os.listdir(INPUT_DIR) if f.endswith(".c")])
count=0
for filename in loop_files:
    filepath = os.path.join(INPUT_DIR, filename)
    with open(filepath, "r") as file:
        base_code = file.read()

    match = re.search(r'for \(int i = 0; i < N; i\+\+\) \{\s*for \(int j = 0; j < N; j\+\+\) \{\s*((?:.|\n)*?)\s*\}\s*\}', base_code)
    if not match:
        print(f"❌ Loop body not found in {filename}")
        continue

    inner_body = match.group(1).strip()

    for ts in tile_sizes:
        for order_name, order in loop_orders.items():
            header = base_code.split("int main() {")[0]
            tiled_loop = f"""int main() {{
    float A[N][N], B[N][N], C[N][N], X[N], Y[N], Z[N];
    int T = {ts};
    for (int {order[0]} = 0; {order[0]} < N / T; {order[0]}++) {{
        for (int {order[1]} = 0; {order[1]} < N / T; {order[1]}++) {{
            for (int {order[2]} = T * {order[0]}; {order[2]} < T * {order[0]} + T; {order[2]}++) {{
                for (int {order[3]} = T * {order[1]}; {order[3]} < T * {order[1]} + T; {order[3]}++) {{
"""

            # safe replacements using regex
            tiled_body = re.sub(r'\bi\b', order[2], inner_body)
            tiled_body = re.sub(r'\bj\b', order[3], tiled_body)
            indented_body = "\n".join(["                    " + line for line in tiled_body.splitlines()])

            tiled_loop += indented_body
            tiled_loop += "\n                }\n            }\n        }\n    }\n    return 0;\n}"

            variant_filename = f"{filename[:-2]}_T{ts}_{order_name}.c"
            variant_path = os.path.join(OUTPUT_DIR, variant_filename)
            with open(variant_path, "w") as vf:
                vf.write(header + tiled_loop)
            
    count += 36  
    if(count==72000):
        OUTPUT_DIR = "loop_variants/Batch2"
        os.makedirs(OUTPUT_DIR, exist_ok=True)
    elif(count==144000):
        OUTPUT_DIR = "loop_variants/Batch3"
        os.makedirs(OUTPUT_DIR, exist_ok=True)
    elif(count==216000):
        OUTPUT_DIR = "loop_variants/Batch4"
        os.makedirs(OUTPUT_DIR, exist_ok=True)
    elif(count==288000):
        OUTPUT_DIR = "loop_variants/Batch5"
        os.makedirs(OUTPUT_DIR, exist_ok=True)

    print(count)
    # if(count==216):
    #     break

print("✅ All loop variants (36 per loop) generated in 'loop_variants/' folder.")
