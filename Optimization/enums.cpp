#include <iostream>
/*
this code will becaus ehow state and mode have the same enumerators
this can be bad if you have a large system cause now you have to write different enumerators for each enum and it can be confusing to know which one is which

enum Mode{Manual, Automatic, SemiAutomatic};
enum state{Manual, Automatic, SemiAutomatic};
*/
 
// now we can use enum class to avoid this problem, see how both have the same enumerators but in different scopes and don't conflict with each other
enum class Mode { Manual, Automatic, SemiAutomatic };
enum class State { Manual, Automatic, SemiAutomatic };

int main() {
    // to acess the actual enum we need the scope then :: then the enumerator like you see here

    Mode mode = Mode::Manual;
    State state = State::Automatic;

    

    // here is some random code that would use this in an actual application
    switch (mode){
        case Mode::Manual:
            std::cout << "Mode is Manual\n";
            break;
        case Mode::Automatic:
            std::cout << "Mode is Automatic\n";
            break;
        case Mode::SemiAutomatic:
            std::cout << "Mode is SemiAutomatic\n";
            break;
    }

    switch (state){
        case State::Manual:
            std::cout << "State is Manual\n";
            break;
        case State::Automatic:
            std::cout << "State is Automatic\n";
            break;
        case State::SemiAutomatic:
            std::cout << "State is SemiAutomatic\n";
            break;
    }

    return 0;
}