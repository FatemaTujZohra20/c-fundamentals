# c-fundamentals - build every program into build/, mirroring the source tree.
#
#   make            compile everything
#   make run-<name> compile and run one program by its file name
#   make list       show every program that can be run
#   make clean      remove build/

CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -O2
BUILD   := build

SOURCES := $(shell find src problems -name '*.c' 2>/dev/null)
TARGETS := $(patsubst %.c,$(BUILD)/%,$(SOURCES))

.PHONY: all clean list help

all: $(TARGETS)
	@echo "Built $(words $(TARGETS)) programs into $(BUILD)/"

$(BUILD)/%: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ $<
	@echo "  CC  $<"

# make run-pointer_basics  ->  finds and runs that program
run-%:
	@source=$$(find src problems -name '$*.c' | head -1); \
	if [ -z "$$source" ]; then \
		echo "No program named '$*'. Try: make list"; exit 1; \
	fi; \
	target=$(BUILD)/$${source%.c}; \
	$(MAKE) --no-print-directory -s $$target; \
	echo "--- running $$target ---"; \
	$$target

list:
	@echo "Available programs:"
	@for s in $(SOURCES); do \
		name=$$(basename $$s .c); \
		printf "  %-34s %s\n" "$$name" "$$s"; \
	done | sort -k2

help:
	@echo "make            compile every program into $(BUILD)/"
	@echo "make run-NAME   compile and run one program (see: make list)"
	@echo "make list       list every program"
	@echo "make clean      remove $(BUILD)/"

clean:
	@rm -rf $(BUILD)
	@echo "Removed $(BUILD)/"
