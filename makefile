CC = gcc
CFLAGS = -c -Wall
LDFLAGS = -lm
BINDIR = bin
SRCDIR = src
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(addprefix $(BINDIR)/, $(notdir $(SRC:.c=.o)))
#HEAD = $(filter-out $(SRCDIR)/structure_constant.h, $(wildcard $(SRCDIR)/*.h))
HEADALL = $(SRCDIR)/structures.h $(SRCDIR)/defines.h
PROG = $(BINDIR)/predictionPrixAirbnb

all: $(PROG)

$(PROG): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BINDIR)/main.o: $(SRCDIR)/main.c $(HEADALL) $(BINDIR)
	$(CC) $(CFLAGS) $< -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h $(HEADALL) $(BINDIR)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)

