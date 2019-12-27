def merge_many_to_one(pwd_files, merged_filename):
    fout = open(merged_filename, "w")
    for pwd_file in pwd_files:
        fin = open(pwd_file, "r")
        for pwd in fin:
            fout.write(pwd)
        fin.close()
        fout.flush()
    fout.flush()
    fout.close()
    pass
