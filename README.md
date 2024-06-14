# Simple Blockchain Implementation in C
By Irvin Cardoza

This project implements a basic blockchain structure in C language, using linked lists to store blocks and the SHA-256 hashing algorithm from CommonCrypto for hashing. We use CommonCrypto as it is convinient for Macos users.

## Features

- **Blockchain Structure**: Implemented using a linked list of blocks.
- **Hashing**: Utilizes SHA-256 hashing algorithm to secure block integrity.
- **User Interaction**: Allows users to add data interactively to the blockchain.

## Requirements

- **C Compiler**: Ensure you have a C compiler installed on your system.
- **CommonCrypto Library**: This program uses the CommonCrypto library for SHA-256 hashing. Make sure it's available on your development environment.

## How to Use

1. **Compile the Program**:
   - Open a terminal or command prompt.
   - Navigate to the directory containing `blockchain.c`.
   - Compile the program by running using GCC.
   - The convinience of using CommonCrypto is by just importing library we can directly run code without any installatioms.

   

2. **Run the Program**:
   - Ideally run on VSCode with gcc compiler preinstalled.

     

3. **Interact with the Blockchain**:
   - Follow the prompts to add blocks to the blockchain.
   - Enter data for each block when prompted.
   - Continue adding blocks as desired.

4. **View Blockchain Contents**:
   - Once you finish adding blocks, the program will display the contents of the blockchain.
   - Each block's index, timestamp, data, previous hash, and hash will be shown.

5. **Clean Up**:
   - The program automatically frees allocated memory when it exits.
   - No additional clean-up steps are required after running the program.

## Example

Here's a brief example of the program in action:
## Example

```plaintext
$ ./blockchain
Enter data for the new block: First block
Block added to blockchain.
Do you want to add another block? (y/n): y
Enter data for the new block: Second block
Block added to blockchain.
Do you want to add another block? (y/n): n
Blockchain contents:
Block: 0
Timestamp: [timestamp]
Data: First block
Previous Hash: 0
Hash: [hash]

Block: 1
Timestamp: [timestamp]
Data: Second block
Previous Hash: [hash of first block]
Hash: [hash]
```

### Notes:
- Replace `[timestamp]`, `[hash]`, and other placeholders with actual values displayed by your program during runtime.
- This example demonstrates the interactive nature of the program where users can add blocks to the blockchain sequentially.
- The blockchain contents section displays each block's index, timestamp, data, previous hash, and hash after adding blocks as described.

### Problems encountered:
- The main issue I had was using the openssl to use sha.h library. I then found CommonCrypto to solve my issues. 


