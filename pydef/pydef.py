import yaml

from headergen import Header
import networkx as nx
from matplotlib import pyplot as plt
from tasks import Tasks


def read_yaml_file(file_path):
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


T = Tasks()
d = read_yaml_file("example.yaml")
T.build_tasks_dict(d)

if not T.check_dependencies_consistency():
    print("ERROR: can not procede due to tasks inconsisntency")
    exit()

T.build_tasks_graph()

H = Header()
T.generate_tasks_defines(H)
H.write_file("header.h")

nx.draw(T.get_tasks_graph(), with_labels=True)
plt.show()
