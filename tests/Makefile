# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 08:00:32 by ikgonzal          #+#    #+#              #
#    Updated: 2022/12/05 12:46:09 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	all clean fclean re run vector stack map benchmarks

all:
	@ clear
	@ echo "\033[1m\033[33mCOMPILING STACK AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make -C ./stack_tests/
	@ clear
	@ echo "\033[1m\033[33mCOMPILING VECTOR AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make -C ./vector_tests/
	@ clear
	@ echo "\033[1m\033[33mCOMPILING MAP AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make -C ./map_tests/

clean:
	@ make clean -C ./stack_tests/
	@ make clean -C ./vector_tests/
	@ make clean -C ./map_tests/

fclean:
	@ make fclean -C ./stack_tests/
	@ make fclean -C ./vector_tests/
	@ make fclean -C ./map_tests/

re:		all fclean

run:		all
	@ clear
	@ make run -C ./stack_tests/
	@ clear
	@ make run -C ./vector_tests/
	@ clear
	@ make run -C ./map_tests/
	@ clear

stack:
	@ echo "\033[1m\033[33mCOMPILING STACK AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make run -C ./stack_tests/
	@ make fclean -C ./stack_tests/

vector:
	@ echo "\033[1m\033[33mCOMPILING VECTOR AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make run -C ./vector_tests/
	@ make fclean -C ./vector_tests/

map:
	@ echo "\033[1m\033[33mCOMPILING MAP AND CREATING EXECUTABLES\033[39m\033[0m"
	@ make run -C ./map_tests/
	@ make fclean -C ./map_tests/