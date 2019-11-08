import yaml
import sys

from headergen import Header
import networkx as nx
from matplotlib import pyplot as plt
from tasks import Tasks
from applications import Applications


def read_yaml_file(file_path):
    """Build a dictionary from the YAML config file

    Parameters
    ----------

    file_path : str
        Path to the YAML configuration file

    Returns
    -------

    dict
        A dictionary storing the configuration
    """
    config_dict = {}
    try:
        with open(file_path) as stream:
            try:
                config_dict = yaml.safe_load(stream)
            except yaml.YAMLError as exc:
                print("ERROR: invalid yaml")
                print(exc)
    except:
        print("ERROR: error while opening file %s" % (file_path))
    return config_dict


def is_dangerous(output_type):
    """Tells if an output type may pose a threat to consistency

    Not really implemented, just a stub
    """
    if output_type.endswith("*"):
        return True
    return False


"""
ENTRY POINT
"""

if len(sys.argv)<2:
    print("ERROR: missing YAML file")
    print("Usage: pydef.py <YAML file> [output path]")
    sys.exit(1)

T = Tasks()
A = Applications()
d = read_yaml_file(sys.argv[1])
T.build_tasks_dict(d)
A.build_apps_dict(d, T.get_tasks_dict())
T.set_apps_dict(A.get_apps_dict())

if not T.check_dependencies_consistency():
    print("ERROR: can not procede due to tasks inconsisntency")
    exit()

T.build_tasks_graph()
G = T.get_tasks_graph()

warnings = False

for node in G.nodes():
    if G.out_degree(node) > 1 and is_dangerous(T.get_tasks_dict()[node].output.type):
        # check consistency
        print("WARNING: potential hidden dependency from %s" % (node))

H = Header()
H.add_prefixes(d.get("HEADER PREFIX", []))
T.generate_tasks_defines(H)
A.generate_apps_defines(H)
output_path = "header.h"
if len(sys.argv)>=3:
    output_path = sys.argv[2]
H.write_file(output_path)

# nx.draw(T.get_tasks_graph(), with_labels=True)
# plt.show()
