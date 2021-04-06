from cs50 import get_string

# The purpose of this program is to compute the approximate US Grade level required to comprehend some text that is input by the user, using the
# Coleman-Liau index which is a simple formula computed from the number of letters, words and sentences: index = 0.0588 * L - 0.296 * S - 15.8
# Grades fall between 1 and 16+
# L is the average number of letters per 100 words
# S is the average number of sentences per 100 words in the text


def main():
    text = input("Text: ")
    length = len(text)

    letters = 0
    words = 1
    sent = 0

    # Here we count the number of alphabetical letters in the text by going through each character to check if it is either a lower case letter or an upper case letter
    for i in range(length):
        if text[i].isalpha():
            letters += 1

    words = len(text.split())
    sent = sentences(text)

    L = letters * 100 / words
    S = sent * 100 / words

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")

    elif index >= 1 and index < 16:
        print(f"Grade  {index}")

    else:
        print("Grade 16+")


def sentences(text):

    list1 = []
    listfinal = []

    Sentences = text.split(". ")

    for sentence in Sentences:
        list2 = sentence.split("! ")
        for elem in list2:
            list1.append(elem)

    for elem in list1:
        templist = elem.split("? ")
        for elem in templist:
            listfinal.append(elem)

    return len(listfinal)


if __name__ == "__main__":
    main()
