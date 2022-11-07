
all: 
	make -C srcs

clean:
	-make -C srcs clean
	-make -C srcs_bonus clean

fclean:
	-make -C srcs fclean
	-make -C srcs_bonus fclean
	
re: fclean all

bonus: 
	make -C srcs_bonus


.PHONY: all init clean flcean re
