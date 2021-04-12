import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)



# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        #if not request.form.get("name") or request.for.get("sport") not in SPORTS:
            #return render_template("failure.html")
        name = request.form.get("name")
        if not name:
            return render_template("error.html", message = "Missing Name")
        month = request.form.get("month")
        if not month:
            return render_template("error.html", message = "Missing Month")
        day = request.form.get("day")
        if not day:
            return render_template("error.html", message = "Missing Day")

        # Insert data into database
        db.execute("INSERT into birthdays (name, month, day) VALUES (?,?,?)", name, month, day)

        # Go back to homepage
        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        birthdays = db.execute("SELECT * FROM birthdays")

        # render birthdays page
        return render_template("index.html", birthdays = birthdays)

@app.route("/greet", methods = ["GET", "POST"])
def greet():
    #return render_template("greet.html", month = request.args.get("month", "world"))
    #return render_template("greet.html", month = request.form.get("month", "world"))
    return render_template("index.html", month = request.form.get("month", "world"))
