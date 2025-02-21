.PHONY: test clean

test: 
	g++ -o test_binary test/run_tests.cpp && ./test_binary

clean:
	rm -f test_binary