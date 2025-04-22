# benchmark_variants.py - compile and time each loop variant
import os
import subprocess
import time

VARIANT_DIR = "loop_variants"
RESULT_FILE = "benchmark_results.csv"
EXECUTABLE = "loop_exec"

# Collect all C files
variant_files = sorted([f for f in os.listdir(VARIANT_DIR) if f.endswith(".c")])

# Prepare CSV header

with open(RESULT_FILE, "w") as out:
    out.write("loop_id,tile_size,loop_order,exec_time_ms\n")
    count=1
    for filename in variant_files:
        filepath = os.path.join(VARIANT_DIR, filename)
        print(f"{count} Benchmarking {filename}...")
        count+=1

        # Compile the C file
        compile_cmd = ["gcc", filepath, "-O3", "-o", EXECUTABLE, "-lm"]
        compile_result = subprocess.run(compile_cmd, capture_output=True, text=True)

        if compile_result.returncode != 0:
            print(f"❌ Compilation failed for {filename}\n{compile_result.stderr}")
            continue

        # Run the binary and time it
        start = time.perf_counter()
        run_result = subprocess.run([f"./{EXECUTABLE}"], capture_output=True)
        end = time.perf_counter()

        exec_time_ms = (end - start) * 1000  # convert to milliseconds

        # Parse filename: loop_code_3_T32_L5.c → loop_id=3, tile_size=32, order=L5
        parts = filename[:-2].split("_")
        loop_id = parts[2]
        tile_size = parts[3][1:]
        loop_order = parts[4]

        out.write(f"{loop_id},{tile_size},{loop_order},{exec_time_ms:.3f}\n")

print("✅ Benchmarking complete. Results saved to benchmark_results.csv")