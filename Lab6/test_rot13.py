import subprocess
import sys
from pathlib import Path

# Expected ROT13 output for contents of input.txt
EXPECTED = (
    "Guvf vf gur qnl gur Ybeq unf znqr.  Yrg hf erwbvpr naq or tynq va vg. nfqswunfqsxwu"
)

LAB_DIR = Path(__file__).parent
CPP_FILE = LAB_DIR / "Lab6.cpp"
EXECUTABLE = LAB_DIR / "rot13_test"
INPUT_FILE = LAB_DIR / "input.txt"
OUTPUT_FILE = LAB_DIR / "output.rot13"

# Compile the program
compile_proc = subprocess.run([
    "g++",
    str(CPP_FILE),
    "-o",
    str(EXECUTABLE),
], capture_output=True, text=True)

if compile_proc.returncode != 0:
    sys.stderr.write("Compilation failed:\n")
    sys.stderr.write(compile_proc.stdout)
    sys.stderr.write(compile_proc.stderr)
    sys.exit(1)

# Run the program providing the input file name
run_proc = subprocess.run(
    [str(EXECUTABLE)],
    input=f"{INPUT_FILE.name}\n",
    text=True,
    cwd=LAB_DIR,
    capture_output=True,
)

if run_proc.returncode != 0:
    sys.stderr.write("Execution failed:\n")
    sys.stderr.write(run_proc.stdout)
    sys.stderr.write(run_proc.stderr)
    sys.exit(1)

# Read produced output
result = OUTPUT_FILE.read_text()

if result == EXPECTED:
    print("Rot13 test passed")
    sys.exit(0)
else:
    print("Rot13 test failed")
    print("Expected:", EXPECTED)
    print("Got:", result)
    sys.exit(1)
