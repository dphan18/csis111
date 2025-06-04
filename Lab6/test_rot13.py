import subprocess
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

def test_rot13():
    # Compile the program
    compile_proc = subprocess.run([
        "g++",
        str(CPP_FILE),
        "-o",
        str(EXECUTABLE),
    ], capture_output=True, text=True)
    assert (
        compile_proc.returncode == 0
    ), f"Compilation failed:\n{compile_proc.stdout}{compile_proc.stderr}"

    # Run the program providing the input file name
    run_proc = subprocess.run(
        [str(EXECUTABLE)],
        input=f"{INPUT_FILE.name}\n",
        text=True,
        cwd=LAB_DIR,
        capture_output=True,
    )
    assert (
        run_proc.returncode == 0
    ), f"Execution failed:\n{run_proc.stdout}{run_proc.stderr}"

    # Read produced output
    result = OUTPUT_FILE.read_text()
    assert result == EXPECTED, f"Expected: {EXPECTED!r}\nGot: {result!r}"
