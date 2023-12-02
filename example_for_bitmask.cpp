#include <iostream>
#include <bitset>

int main() {
    // Assume each question has 4 choices (A, B, C, D)
    const int numQuestions = 15;

    // Initialize an array to store answers (2 bits for each question)
    uint32_t answerMask = 0;

    // Set answers for questions (for example)
    for (int question = 0; question < numQuestions; ++question) {
        char userAnswer; // Assuming user selects A, B, C, or D

        // Get the user's answer (you can replace this with your input mechanism)
        std::cout << "Enter the answer for question " << (question + 1) << ": ";
        std::cin >> userAnswer;

        // Convert the answer to a bitmask (assuming A, B, C, D)
        uint32_t answerBit = 0;
        switch (userAnswer) {
            case 'A':
                answerBit = 0b00;
                break;
            case 'B':
                answerBit = 0b01;
                break;
            case 'C':
                answerBit = 0b10;
                break;
            case 'D':
                answerBit = 0b11;
                break;
            default:
                std::cerr << "Invalid answer entered!" << std::endl;
                return 1;
        }

        // Store the answer in the bitmask for the corresponding question
        answerMask |= (answerBit << (question * 2));
    }

    // Print the bitmask (for demonstration purposes)
    std::cout << "Answer bitmask: " << std::bitset<30>(answerMask) << std::endl;

    return 0;
}
