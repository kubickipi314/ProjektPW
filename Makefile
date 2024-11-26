CXX = g++
CXXFLAGS = -O3

SRC_DIR = src
BIN_DIR = bin
TEST_IN_DIR = test_in
TEST_OUT_DIR = test_out

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
BINARIES = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%, $(SOURCES))

FLAGS_OMP = -fopenmp
FLAGS_THREADS = -pthread

all: $(BINARIES)

$(BIN_DIR)/D: $(SRC_DIR)/D.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/D2: $(SRC_DIR)/D2.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/D3: $(SRC_DIR)/D3.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/Do: $(SRC_DIR)/Do.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@ -fopenmp

$(BIN_DIR)/Do2: $(SRC_DIR)/Do2.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@ -fopenmp

$(BIN_DIR)/Dt: $(SRC_DIR)/Dt.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@ -pthread

$(BIN_DIR)/Dt2: $(SRC_DIR)/Dt2.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@ -pthread

$(BIN_DIR)/gen: $(SRC_DIR)/gen.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR)/* $(TEST_OUT_DIR)/*
