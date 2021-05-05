CC = g++
INC = include
SRC = src

driver : driver.cpp $(SRC)/LinkedList.o $(SRC)/AlphabetTrie.o $(SRC)/BinarySearchTree.o $(SRC)/ArrayAlgorithms.o $(SRC)/Graph.o
	$(CC) driver.cpp $(SRC)/LinkedList.o $(SRC)/AlphabetTrie.o $(SRC)/BinarySearchTree.o $(SRC)/ArrayAlgorithms.o $(SRC)/Graph.o -o driver

$(SRC)/LinkedList.o : $(SRC)/LinkedList.cpp $(SRC)/$(INC)/LinkedList.h
	$(CC) -c $(SRC)/LinkedList.cpp -o $(SRC)/LinkedList.o

$(SRC)/AlphabetTrie.o : $(SRC)/AlphabetTrie.cpp $(SRC)/$(INC)/AlphabetTrie.h
	$(CC) -c $(SRC)/AlphabetTrie.cpp -o $(SRC)/AlphabetTrie.o

$(SRC)/BinarySearchTree.o : $(SRC)/BinarySearchTree.cpp $(SRC)/$(INC)/BinarySearchTree.h
	$(CC) -c $(SRC)/BinarySearchTree.cpp -o $(SRC)/BinarySearchTree.o

$(SRC)/ArrayAlgorithms.o : $(SRC)/ArrayAlgorithms.cpp $(SRC)/$(INC)/ArrayAlgorithms.h
	$(CC) -c $(SRC)/ArrayAlgorithms.cpp -o $(SRC)/ArrayAlgorithms.o

$(SRC)/Graph.o : $(SRC)/Graph.cpp $(SRC)/$(INC)/Graph.h
	$(CC) -c $(SRC)/Graph.cpp -o $(SRC)/Graph.o

clean:
	rm -f $(SRC)/*.o driver *.o