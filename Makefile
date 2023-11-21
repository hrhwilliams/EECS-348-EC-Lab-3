CPP := g++ -std=c++17
CPPFLAGS := -O1

bank: main.cpp account.cpp savings_account.cpp current_account.cpp
	$(CPP) $(CPPFLAGS) $^ -o $@
