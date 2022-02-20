/* -----------------------------------------------------------------------------

FILE NAME:         Encryption.cpp

DESCRIPTION:       Main file for milestone Three

PURPOSE:           contains enchancements of files for project one

USAGE:             make using first example below, then run using second example

EXAMPLES:          make (FILE NAME), ./(FILE NAME)

PARAMETERS:        none

EXIT CODES:        0 = Success
                   Otherwise = Error

COMPILATION:       gnu g++

NOTES:             

MODIFICATION HISTORY:

Author          Date			Modification(s)
-------------   -----------		---------------
Austin Orr      01-30-2022		Start programing
----------------------------------------------------------------------------- */

#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>

/// <summary>
/// encrypt or decrypt a source string using the provided key
/// </summary>
/// <param name="source">input string to process</param>
/// <param name="key">key to use in encryption / decryption</param>
/// <returns>transformed string</returns>
std::string encrypt_decrypt(const std::string& source, const std::string& key)
{
    // get lengths now instead of calling the function every time.
    // this would have most likely been inlined by the compiler, but design for perfomance.
    const auto key_length = key.length();
    const auto source_length = source.length();

    // assert that our input data is good
    assert(key_length > 0);
    assert(source_length > 0);

    std::string output = source;

    // loop through the source string char by char
    for (size_t i = 0; i < source_length; ++i)
    { 
      // transform each character based on an xor of the key modded constrained to key length using a mod
        output[i] = source[i] ^ key_length;
    }



    // our output length must equal our source length
    assert(output.length() == source_length);

    // return the transformed string
    return output;
}

std::string hex(const std::string& source) {

    // get lengths now instead of calling the function every time.
    // this would have most likely been inlined by the compiler, but design for perfomance.
    const auto source_length = source.length();

    std::hash<std::string> hasher;

    // assert that our input data is good
    assert(source_length > 0);

    std::string output = source;

    //hashes file
    size_t hash = hasher(source);

    //convert size_t variable to string
    output = std::to_string(hash);

    // return the transformed string
    return output;
}

std::string read_file(const std::string& filename)
{
    std::string file_text = "John Q. Smith\nThis is my test string";



    //Designates file
    std::ifstream input(filename);


    // Reads file
    file_text.assign((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));


    return file_text;
}

std::string get_student_name(const std::string& string_data)
{
    std::string student_name;

    // find the first newline
    size_t pos = string_data.find('\n');
    // did we find a newline
    if (pos != std::string::npos)
    { // we did, so copy that substring as the student name
        student_name = string_data.substr(0, pos);
    }

    return student_name;
}

void save_data_file(const std::string& filename, const std::string& student_name, const std::string& key, const std::string& data)
{
  

      //set up time
    std::time_t rawtime = std::time(nullptr);

    //Sets up output file
    std::ofstream output;

    //OPens output file
    output.open(filename);

    //Writes info to output file
    output << "Name: " << student_name << std::endl
        << "Time: " << rawtime << std::endl
        << "Key: " << key << std::endl
        << "Data: " << data << std::endl;

    //closes output file
    output.close();

}

//Random number generator for very basic double verification
std::string randomNum() {

    //Seed
    srand(time(NULL));

    //Random number between 10000 and 1
    int secret = rand() % 10000 + 1;

    //Converts to string
    std::string text = std::to_string(secret);

    return text;
}

int main()
{
    std::string verify = "";

    std::cout << "Encyption Decryption Test!" << std::endl;

    // input file format
    // Line 1: <students name>
    // Line 2: <Lorem Ipsum Generator website used> https://pirateipsum.me/ (could be https://www.lipsum.com/ or one of https://www.shopify.com/partners/blog/79940998-15-funny-lorem-ipsum-generators-to-shake-up-your-design-mockups)
    // Lines 3+: <lorem ipsum generated with 3 paragraphs> 
    //  Fire in the hole bowsprit Jack Tar gally holystone sloop grog heave to grapple Sea Legs. Gally hearties case shot crimp spirits pillage galleon chase guns skysail yo-ho-ho. Jury mast coxswain measured fer yer chains man-of-war Privateer yardarm aft handsomely Jolly Roger mutiny.
    //  Hulk coffer doubloon Shiver me timbers long clothes skysail Nelsons folly reef sails Jack Tar Davy Jones' Locker. Splice the main brace ye fathom me bilge water walk the plank bowsprit gun Blimey wench. Parrel Gold Road clap of thunder Shiver me timbers hempen halter yardarm grapple wench bilged on her anchor American Main.
    //  Brigantine coxswain interloper jolly boat heave down cutlass crow's nest wherry dance the hempen jig spirits. Interloper Sea Legs plunder shrouds knave sloop run a shot across the bow Jack Ketch mutiny barkadeer. Heave to gun matey Arr draft jolly boat marooned Cat o'nine tails topsail Blimey.

    std::string num = randomNum();

    //Displays random number and asks to repeat number
    std::cout << "Your number is: " << num << std::endl;
    std::getline(std::cin, verify);

    //Checks number inputted to number genrated if correct will run rest of code
    if (verify != num) {
        std::cout << "incorrect number" << std::endl;
    }
    else if (verify == num) {
        const std::string file_name = "inputdatafile.txt";
        const std::string encrypted_file_name = "encrypteddatafile.txt";
        const std::string decrypted_file_name = "decrytpteddatafile.txt";
        const std::string hex_encrypted_file_name = "hexencrypteddatafile.txt";
        const std::string source_string = read_file(file_name);
        const std::string key = "password";

        // get the student name from the data file
        const std::string student_name = get_student_name(source_string);

        // encrypt sourceString with key
        const std::string encrypted_string = encrypt_decrypt(source_string, key);

        //Encrypts data to hash format
        const std::string hex_encrypt = hex(source_string);

        // save encrypted_string to file
        save_data_file(encrypted_file_name, student_name, key, encrypted_string);

        //saves hash encryption to file
        save_data_file(hex_encrypted_file_name, student_name, key, hex_encrypt);

        // decrypt encryptedString with key
        const std::string decrypted_string = encrypt_decrypt(encrypted_string, key);

        // save decrypted_string to file
        save_data_file(decrypted_file_name, student_name, key, decrypted_string);

        std::cout << "Read File: " << file_name << " - Encrypted To: " << encrypted_file_name << " - Decrypted To: " << decrypted_file_name << std::endl;
    }
    else {
        std::cout << "Please do not resist human!!" << std::endl;
    }
    // students submit input file, encrypted file, decrypted file, source code file, and key used
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
