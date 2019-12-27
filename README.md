# Password Tools

## List of tools

this is a project of password tools which includes:

1. compare guesses with test set
2. draw the picture of guess-crack curve
3. count the length statistics of several dataset
4. sample some passwords form a dataset
5. split the dataset to several training set and test set (k-fold)


## Usage

### compare_guesses_with_test.py
```shell script
$ python compare_guesses_with_test.py -h
usage: Compare guesses with test set [-h] --guesses GUESSES --test TEST
                                     --cracked CRACKED --curve CURVE
                                     [--split SPLIT] [--ratio]
```

### draw_guess_crack_curve_single_pwd_model.py
```shell script
$ python draw_guess_crack_curve_single_pwd_model.py -h
usage: draw_guess_crack_curve_single_pwd_model.py [-h] --files FILES
                                                  [FILES ...] [--split SPLIT]
                                                  --model MODEL --save SAVE
```

### len_count
```shell script
$ ./len_count
        len_count -f <files>... -t <tags>... [-l <length_lower_bound>] [-u <length_upper_bound>]
```

### k_folder
```shell script
$ ./k_folder                                                                                                 
        k-folder -f <password file> -k <k folder> -t <training files>... -s <testing files>...
```

### random_sample
```shell script
$ ./random_sample                                                                                                                        
        random_sample -f <password file> -s <sampled file> -n <sample size> [-l <lower bound>] [-u
                      <upper bound>]
```