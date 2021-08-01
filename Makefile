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
GFLAGS = -Wall -Werror -g -O0
DEPS = $(SOURCES:.cpp=.d)
CPPFLAGS = -E

CC = g++
SIZE = size
OBJDUMP = objdump
LD=ld
LDFLAGS = -Wl,-Map=$(TARGET).map

%.o : %.cpp
	$(CC) $(INCLUDES) -c $< $(GFLAGS) -o $@
%.i : %.cpp
	$(CC) $(INCLUDES) -c $(CPPFLAGS)  $< $(GFLAGS) -o $@
%.asm : %.cpp
	$(CC) $(INCLUDES) -S $< $(GFLAGS) -o $@
%.d : %.cpp
	$(CC) $(INCLUDES) -M $< $(GFLAGS) -o $@

.PHONY: all
build: all
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) $(GFLAGS) -o $@.out

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(GFLAGS) -o $(TARGET).out

.PHONY: build
build: $(OBJS) $(DEPS)
	$(CC) $(INCLUDES) $(OBJS) $(GFLAGS) -o $(TARGET).out
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out
.PHONY: debug
debug: $(OBJS) $(DEPS)
	$(CC) $(INCLUDES) $(OBJS) -ggdb -o $(TARGET).out
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out

.PHONY: clean
clean:
	rm -f *.o *.i *.map *.out *.asm *.d
