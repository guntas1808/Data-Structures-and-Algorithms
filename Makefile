CC = g++
INC = include
SRC = src

driver : driver.cpp $(SRC)/LinkedList.o $(SRC)/AlphabetTrie.o
	$(CC) driver.cpp $(SRC)/LinkedList.o $(SRC)/AlphabetTrie.o -o driver

$(SRC)/LinkedList.o : $(SRC)/LinkedList.cpp $(SRC)/$(INC)/LinkedList.h
	$(CC) -c $(SRC)/LinkedList.cpp -o $(SRC)/LinkedList.o

$(SRC)/AlphabetTrie.o : $(SRC)/AlphabetTrie.cpp $(SRC)/$(INC)/AlphabetTrie.h
	$(CC) -c $(SRC)/AlphabetTrie.cpp -o $(SRC)/AlphabetTrie.o

clean:
	rm -f $(SRC)/*.o driver *.o