# file-encryption-decryption-tool
A simple file encryption and decryption tool using C and XOR logic

# 🔐 File Encryption and Decryption Tool in C

This project is a simple console-based application written in C for encrypting and decrypting text files using XOR logic and a password/key provided by the user.

---

## 💡 Features

- Encrypt any text file using a key
- Decrypt back using the same key
- File existence validation before encryption/decryption
- ASCII-based XOR operation on each character
- Console interface with feedback using `Sleep()`

---

## 🛠️ Tech Stack

- **Language**: C  
- **Platform**: Windows  
- **Libraries Used**: stdio.h, stdlib.h, string.h, windows.h

---

## 🧪 How It Works

1. User inputs:
   - Input file name
   - Output file name
   - Password (used as key)
2. Program generates a key using the sum of ASCII values of the password.
3. Each character from the input file is XORed with this key and written to the output.
4. Decryption uses the same logic with the same password to get the original file.

---

## 📂 Files

- `main.c` → source code
- `sample.txt` → sample test file
- `output_encrypted.txt` → sample encrypted result
- `README.md` → project explanation

---

## 🔐 Sample Output

Input: HELLO WORLD
Password: hello123
Encrypted: (random ASCII junk)
Decrypted: HELLO WORLD

---

## 🙋‍♂️ Author

**Yash Pathak**  
📫 pathak.y00007@gmail.com / www.linkedin.com/in/yash-pathak-b2a995278
  
🌐 GitHub: https://github.com/yashpathak-007

---

## ⭐️ Star this repo if it helped you!
