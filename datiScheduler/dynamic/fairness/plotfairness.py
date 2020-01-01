import pandas as pd
import sys
import subprocess
from matplotlib import pyplot as plt

file_path = sys.argv[1]
number = int(sys.argv[2])
output_path = "{}.pdf".format(file_path)
fig, ax_fairness = plt.subplots()
ax_tput = ax_fairness.twinx()
ax_tput.set(ylabel="Throughput [times/s]")
ax_tput.set_ylim(bottom=0, top=6)
ax_fairness.set(ylabel="Fairness index")
ax_fairness.set_ylim(bottom=0, top=1)

with open(file_path, "r") as f:
    if number == 2:
        df = pd.read_csv(f, delimiter=";", names=["gamma","app_1", "app_2", "sum", "fairness", "App 1 mean throughput", "App 2 mean throughput"])
    else:
        df = pd.read_csv(f, delimiter=";", names=["gamma","app_1", "app_2", "app_3", "sum", "fairness", "App 1 mean throughput", "App 2 mean throughput", "App 3 mean throughput"])
    df.set_index("gamma")
    if number == 2:
        dfavg = df[["App 1 mean throughput", "App 2 mean throughput"]].copy()
    else:
        dfavg = df[["App 1 mean throughput", "App 2 mean throughput", "App 3 mean throughput"]].copy()
    dfavg.plot.bar(rot=1, ax=ax_tput, width=0.3, colormap="Set3")
    df.plot.bar(x="gamma", y="fairness", ax=ax_fairness, legend=False, subplots=True, label="")
    ax_fairness.set_xlabel("Gamma")
    ax_tput.set_xlabel("")
    plt.savefig(output_path)
    subprocess.run(["pdfcrop", output_path, output_path])

