###################################################################################
#
#
#
#
#
#
###################################################################################

include sources.mk

TARGET = conway
OBJS = $(SOURCES:.cpp=.o)
GFLAGS = -Wall -Werror -ggdb -O0
DEPS = $(SOURCES:.cpp=.d)
CPPFLAGS = -E

CC = g++
SIZE = size
OBJDUMP = objdump


%.o : %.cpp
	$(CC) $(INCLUDES) -c $< $(GFLAGS) $@
%.i : %.cpp
	$(CC) $(INCLUDES) -c $(CPPFLAGS)  $< $(GFLAGS) $@
%.asm : %.cpp
	$(CC) $(INCLUDES) -S $< $(GFLAGS) $@
.d : %.cpp
	$(CC) $(INCLUDES) -M $< $(GFLAGS) $@

.PHONY: all
build: all
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) $(GFLAGS) $@

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(GFLAGS) $(TARGET)

.PHONY: build
build: $(OBJS) $(DEPS)
	$(CC) $(INCLUDES) $(OBJS) $(GFLAGS) $(TARGET)
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out
.PHONY: debug
debug: $(OBJS) $(DEPS)
	$(CC) $(INCLUDES) $(OBJS) -ggdb $(TARGET)
	$(SIZE) -Atd $(TARGET)
	$(SIZE) $(TARGET)

.PHONY: clean
clean:
	rm -f *.o *.i *.map *.out *.asm *.d
