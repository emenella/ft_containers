override PATH_I		:= includes/

FT := ft_containers
STD := std_containers

SRCS := main.cpp
OBJS := ${SRCS:.cpp=.o}
HEADER := enable_if.hpp  equal.hpp  exception.hpp  is_integral.hpp  iterator.hpp  iterators_traits.hpp  lexicographical_compare.hpp  map.hpp  map_fct.hpp  pair.hpp  reverse_iterator.hpp  stack.hpp  utils.hpp  vector.hpp

INC		:= -I${PATH_I}
CC		:= g++
FLAG	:= -Wall -Werror -Wextra
CPP_V	:= -std=c++98
CCF		:= ${CC} ${FLAG} ${CPP_V} ${INC}
RM		:= rm -rf

all: $(FT) $(STD)

$(FT): $(SRCS)
	$(CCF) -o $(FT) $(SRCS)

$(STD): $(SRCS)
	$(CCF) -o $(STD) $(SRCS) -D STD

clean:
	${RM} -f $(OBJS) 

fclean:
	${RM} -f $(FT) $(STD) $(OBJS) 

re: fclean all