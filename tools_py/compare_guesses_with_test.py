import argparse
import collections


def compare(guesses_file, test_file, cracked_pwd_file, guess_crack_file, from_len=1, to_len=255, split_chr=" : ",
            with_ratio=True):
    ftest = open(test_file, "r")
    fout_guess_crack = open(guess_crack_file, "w")
    target_pwd_set = collections.defaultdict(int)
    total_pwd_cnt_in_test = 0
    for pwd in ftest:
        pwd = pwd.strip("\r\n")
        if from_len <= len(pwd) <= to_len:
            target_pwd_set[pwd.strip("\r\n")] += 1
            total_pwd_cnt_in_test += 1
    ftest.close()
    fguess = open(guesses_file, "r")
    guess_num = 0
    cracked_num = 0
    step = 1
    batch_size = 100
    guess_list = []
    crack_list = []
    cracked_pwd = []
    for pwd in fguess:
        guess_num += 1
        pwd = pwd.strip("\r\n")
        if pwd in target_pwd_set:
            cracked_num += target_pwd_set[pwd]
            cracked_pwd.append(pwd)
        if guess_num % step == 0:
            guess_list.append(guess_num)
            crack_list.append(cracked_num)
            if guess_num / step == batch_size:
                step *= batch_size
    fguess.close()
    del target_pwd_set
    if with_ratio:
        for guess, crack in zip(guess_list, crack_list):
            fout_guess_crack.write(
                "%d%s%d%s%2.2f\n" % (guess, split_chr, crack, split_chr, round(crack / total_pwd_cnt_in_test * 100, 2)))
    else:
        for guess, crack in zip(guess_list, crack_list):
            fout_guess_crack.write("%d%s%d\n" % (guess, split_chr, crack))
    fout_guess_crack.flush()
    fout_guess_crack.close()
    fout_cracked_pwd = open(cracked_pwd_file, "w")
    fout_cracked_pwd.writelines(["%s\n" % pwd for pwd in cracked_pwd])
    fout_cracked_pwd.flush()
    fout_cracked_pwd.close()
    pass


if __name__ == "__main__":
    parser = argparse.ArgumentParser("Compare guesses with test set")
    parser.add_argument("--guesses", "-g", required=True, help="guesses file")
    parser.add_argument("--test", "-t", required=True, help="test set")
    parser.add_argument("--cracked", "-k", required=True, help="cracked passwords")
    parser.add_argument("--curve", "-c", required=True, help="guess-crack curve file")
    parser.add_argument("--split", "-x", help="splitter of guess-crack file", default=" : ")
    parser.add_argument("--ratio", "-r", help="add ratio to guess-crack file", action="store_true")
    args = parser.parse_args()
    compare(args.guesses, args.test, args.cracked, args.curve, split_chr=args.split, with_ratio=args.ratio)
    pass
