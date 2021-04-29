BIN     := bin
SRC     := src
INCLUDE := include
EXECUTABLE  := maximum_diversity

CXX       := g++
CXX_FLAGS := -I$(INCLUDE) -g 

.PHONY: $(BIN)/$(EXECUTABLE)

all: $(BIN)/$(EXECUTABLE)

debug:	
		@echo "Mode Debug"
		set CXX_FLAGS += -Wall -g
		make

run:
		clear
		@echo "🚀 Executing..."
		./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
		@echo "🚧 Building..."
		mkdir -p $(BIN)
		$(CXX) $(CXX_FLAGS) $^ -o $@

clean:
		@echo "🧹 Clearing..."
		rm -rf $(BIN)