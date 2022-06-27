import os

def get_filepaths(directory):
    """
    This function will generate the file names in a directory 
    tree by walking the tree either top-down or bottom-up. For each 
    directory in the tree rooted at directory top (including top itself), 
    it yields a 3-tuple (dirpath, dirnames, filenames).
    """
    file_paths = []  # List which will store all of the full filepaths.

    # Walk the tree.
    for root, directories, files in os.walk(directory):
        for filename in files:
            # Join the two strings in order to form the full filepath.
            filepath = os.path.join(root, filename)
            file_paths.append(filepath)  # Add it to the list.

    return file_paths  # Self-explanatory.

# Run the above function and store its results in a variable.   
full_file_paths = get_filepaths("D:\OneDrive\Personal\Code\Fun\SAMI WL")

f = open("playerlaknat.sql", "w", encoding="utf-8")

for i in full_file_paths : 
    x = i.replace("D:\OneDrive\Personal\Code\Fun\SAMI WL\\", "")
    x = x.replace(".txt", "")
    string = "INSERT INTO Whitelist_User VALUES (\'" + x + "\'),"
    
    f.write(string)
    f.write("\n")
    print(string)

f.close()