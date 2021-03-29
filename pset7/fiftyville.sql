-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports WHERE year = 2020 AND month = 07 AND day = 28 AND street = "Chamberlin Street";
--from this we learn that the crime took place and the Chamberlin Street Courthouse at 10.15 am and that interviews of witnesses were conducted that same day.
--heft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present
--at the time —
--each of their interview transcripts mentions the courthouse.

SELECT name, transcript FROM interviews WHERE year = 2020 AND month = 07 AND day = 28;

--Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
--If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

--Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
-- I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

--Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
--In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--The thief then asked the person on the other end of the phone to purchase the flight ticket.


SELECT name, phone_number, passport_number, license_plate FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 07 AND day = 28 AND atm_location = "Fifer Street"));

-- suspects ie people who used the ATM at Fifer Street on that day are:
--Bobby
--Elizabeth
--Victoria
--Madison
--Roy
--Danielle
--Russell
-- Ernest
-- Robert

SELECT license_plate, hour, minute FROM courthouse_security_logs WHERE year = 2020 AND month = 07 AND day = 28 AND hour = 10 AND activity = "exit";

--5P2BI95 | 10 | 16 | exit
--94KL13X | 10 | 18 | exit Ernest - was on the exit flight
--6P58WS2 | 10 | 18 | exit
--4328GD8 | 10 | 19 | exit Danielle - was on the exit flight
--G412CB7 | 10 | 20 | exit
--L93JTIZ | 10 | 21 | exit Elizabeth
--322W7JE | 10 | 23 | exit Russell
--0NTHK55 | 10 | 23 | exit
--1106N58 | 10 | 35 | exit Madison - was on the exit flight

-- Fiftyville airport has an id of 8
SELECT * FROM airports WHERE city = "Fiftyville";

SELECT * FROM flights WHERE origin_airport_id = 8 AND year = 2020 AND month = 07 AND day = 29;
-- the first flight the next day is going to an airport with and id of 4 and leaves at 8:20 in the morning

SELECT * FROM airports WHERE id = 4;
--4 | LHR | Heathrow Airport | London flight id is 36

SELECT passport_number FROM passengers WHERE flight_id = 36;

SELECT * from people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);

--Ernest, Madison and Danielle are now our three suspects

SELECT * from atm_transactions WHERE year = 2020 AND month = 07 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw"

SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 07 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw";
SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 07 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw");
SELECT * FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 07 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw"));

SELECT caller, receiver, duration FROM phone_calls WHERE year = 2020 AND month = 07 AND day = 28 AND duration < 60;

SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 07 AND day = 28 AND duration < 60);
-- NOW we know the suspects are Ernest and Madison

--lets look at license plates
SELECT license_plate FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 07 AND day = 28 AND duration < 60);

SELECT * FROM courthouse_security_logs WHERE license_plate IN (SELECT license_plate FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 07 AND day = 28 AND duration < 60));

--261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
--264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
--266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
--267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55
--268 | 2020 | 7 | 28 | 10 | 35 | exit | 1106N58

-- MADIson and Ernest - their cars were outside the courthouse exiting.
-- we Can rule out Madison as his car 1106n58 left at 10.35 and we are told that the thief exited not later than 10.25

SELECT * FROM phone_calls WHERE year = 2020 AND month = 07 AND day = 28 AND duration < 60;

SELECT phone_number FROM people WHERE name = "Ernest"

SELECT receiver FROM phone_calls WHERE year = 2020 AND month = 07 AND day = 28 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE name = "Ernest");

SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE year = 2020 AND month = 07 AND day = 28 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE name = "Ernest"));
