include strategy/makefile
include tools_cpp/makefile
include tools_py/makefile

.PHONY: clean
clean:
	rm -f k_folder
	rm -f random_sample
	rm -f len_count
	rm -f *.py
