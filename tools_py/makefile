
TARGET = venv_init requirements_init picture_single cmp_guess_test
all: $(TARGET)


picture_single: tools_py/draw_guess_crack_curve_single_pwd_model.py
	cp $< .

cmp_guess_test: tools_py/compare_guesses_with_test.py
	cp $< .

venv_init:
	python3 -m venv venv

requirements_init: tools_py/requirements.txt
	venv/bin/pip install -r $<

