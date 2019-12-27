def len_count(filename, lower=4, upper=40):
    counter = {l: 0 for l in range(lower, upper)}
    with open(filename, "r", encoding="utf-16") as fin:
        for line in fin:
            line = line.strip("\r\n")
            if lower <= len(line) <= upper:
                counter[len(line)] += 1
    print(counter)
    pass


len_count("/home/cw/Codes/JavaScript/gpu-guessing/gpu-guessing-back/corpora/dataset/youku_special.txt")
