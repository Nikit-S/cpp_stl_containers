NAME = vector_tests.cpp

all:
	sed 's/ft::vector/std::vector/g' $(NAME) > ch_$(NAME)
	clang++ -std=c++11 $(NAME) -o ft
	clang++ -std=c++11 ch_$(NAME) -o std

test: all
	
	@echo ""
	@echo "--STD--"
	time -p ./std > std.txt
	@echo ""
	@echo "--FT--"
	time -p ./ft > ft.txt
	@echo "--DIFF--"
	@diff std.txt ft.txt > diff.txt
	@cat diff.txt
	@echo "--EODIFF--"
	
clean:
	rm ch_$(NAME) ft std
	
clntxt:
	rm ch_$(NAME) std.txt ft.txt diff.txt

fclean: clean clntxt
