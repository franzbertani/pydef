class Header:

    def __init__(self):
        self.lines = []

    def write_file(self, file_path):
        with open(file_path, "w") as output:
            output.write("\n".join(self.lines))
            #then add helper functions
            with open("helper_functions.c", "r") as infile:
                helper_functions = infile.read()
                output.write(helper_functions)

    def add_define(self, define_tuple):
        self.lines.append("#define %s %s" % (define_tuple[0], define_tuple[1]))

    def add_line(self, string):
        self.lines.append(string)

    def get_var_declaration_string(self, var_type, var_name, value=None):
        string = "%s %s" % (var_type, var_name)
        if value:
            string += " = %s" % (str(value))
        string += ";"
        return string
