helper_functions = "templates/helper_functions.c"
struct_templates = "templates/struct_templates.c"

class Header:
    """This class is an abstraction of the header file

    It contains methods to add defines and write the complete header file.
    """

    def __init__(self):
        self.lines = []

    def write_file(self, file_path):
        """Write on an *.h file the header

        Parameters
        ----------

        file_path : str
            Path to the desired write location
        """
        with open(file_path, "w") as output:
            with open(struct_templates, "r") as st:
                lines = st.read()
                output.writelines(lines)
            output.write("\n".join(self.lines))
            output.write("\n")

            # then add helper functions
            with open(helper_functions, "r") as infile:
                template = infile.read()
                output.write(template)

    def add_define(self, define_tuple):
        """Add a new define to the header file

        Parameters
        ----------

        define_tuple : tuple
            A tuple storing the key and the value of the new define.
            e.g. (A, 42) produces `#DEFINE A 42`
        """
        self.lines.append("#define %s %s" % define_tuple)

    def add_line(self, define_string):
        """Add a line as is to the header

        Parameters
        ----------

        define_string : str
            string to be added as is to the header file
        """
        self.lines.append(define_string)

    def get_var_declaration_string(self, var_type, var_name, value=None):
        """Provides a string with a variable declaration.

        Parameters
        ----------

        var_type : str
            a string representing a valid C type, or a previously defined type
        var_name : str
            a valid C variable identifier
        value : number
            an optional value to initialize the variable

        Returns
        -------
        str
            a C variable declaration that may be used as an input to the
            add_define method
        """
        string = "%s %s" % (var_type, var_name)
        if value:
            string += " = %s" % (str(value))
        string += ";"
        return string
