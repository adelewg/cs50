import csv
import sys


def main():

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # open and save to memory the contents of the database file
    people = []
    file_name = sys.argv[1]
    with open(file_name) as file:
        reader = csv.DictReader(file)
        for line in reader:
            line["AGATC"] = int(line["AGATC"])
            line["AATG"] = int(line["AATG"])
            line["TATC"] = int(line["TATC"])
            #line["TCTAG"] = int(line["TCTAG"])
            people.append(line)

    # Open and save to memory the contents of the text file which is a long sequence of strings
    text_file = sys.argv[2]
    with open(text_file) as f:
        dna_seq = f.read()

    # Check the occurences of AGATC. Uncomment the print statements for debugging
    Agatc = str_repeat(dna_seq, "AGATC")
    # print(f"AGATC  {Agatc}")

    # Check the occurences of AATG
    Aatg = str_repeat(dna_seq, "AATG")
    # print(f"AATG  {Aatg}")

    # Check the occurences of TATC
    Tatc = str_repeat(dna_seq, "TATC")
    # print(f"TATC  {Tatc}")

    # Check the occurences of TCTAG
    Tctag = str_repeat(dna_seq, "TCTAG")
    # print(f"TCTAG  {Tctag}")

    # now we need to iterate over the database looking for a match
    for person in people:
        if person["AGATC"] == Agatc and person["AATG"] == Aatg and person["TATC"] == Tatc:
            print(person["name"])
            return

    print("No match")


def str_repeat(dna_sequence, Str):
    # count the number of occurrences of Str, however these are not necessarity consequtive
    cntOcc = dna_sequence.count(Str)

    # concatenate Str cntOcc times
    max_repeat_string = cntOcc * Str

    while max_repeat_string not in dna_sequence:
        # keep reducing the number of repeats by 1 until you find the number of times the string repeats consecutively
        cntOcc -= 1
        max_repeat_string = cntOcc * Str

    return cntOcc


if __name__ == "__main__":
    main()

