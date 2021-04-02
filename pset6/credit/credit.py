from cs50 import get_int



def main():
    credit = get_int("Number: ")

    # check to see if the number is too short to be a credit card
    if (digits(credit) < 13):
        print("INVALID")
        return

    # check if card is valid by calling check_sum function - card is syntactically valid if this is true
    if (check_sum(credit)):

        # find the 2 digit prefix of number that is 15 digits long
        prefix = credit / 10000000000000
        # find the 2 digit prefix if the number is 16 digits long
        prefix_m = credit / 100000000000000
        # find the single digit prefix if the number is 13 digits long
        prefix_v = credit / 1000000000000
        # find the single digit prefix if the number is 16 digits long
        prefix_vi = credit / 1000000000000000

        length = digits(credit)

        if (length == 15 and (prefix == 34 or prefix == 37)):
            print("AMEX")
            return 0

        elif (length == 16 and (prefix_m == 51 or prefix_m == 52 or prefix_m == 53 or prefix_m == 54 or prefix_m == 55)):
            print("MASTERCARD")
            return 0

        elif ((length == 13 or length == 16) and (prefix_v == 4 or prefix_vi == 4)):

            print("VISA")
            return 0

        else:
            print("INVALID")



    else:
        print("INVALID")





def digits(x):
    counter = 0

    while(x > 0):
        x /= 10
        counter += 1

    return counter

def check_sum(num):

    # initiate a variable to store the sum of every other digit multiplied by 2
    sumTotal = 0
    alt_num = num
    num2 = num

    for i in range (0, digits(num), 2):
        alt_num /= 10
        other = int(2 * (alt_num % 10))
        alt_num /= 10

        if (digits(other) < 2):
            sumTotal += other;

        # if after multiplying by 2 you get two digits - you need to add them digit by digit
        else:
            sumTotal += int(other % 10)
            sumTotal += int(other / 10)

    # now you need to add that temporary number to all the other digits in the credit card that you did not look at
    for i in range (0, digits(num), 2):
        sumTotal += int(num2 % 10)
        num2 /= 100
    print(sumTotal)

    if (sumTotal % 10 == 0):
        return True

    else:
        return False


if __name__ == "__main__":
    main()
