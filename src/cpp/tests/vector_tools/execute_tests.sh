make && ./test_vector_tools && cat results.tex && cat results.tex | grep -i False || printf "\nNo failures\n"
