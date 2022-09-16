import datetime
def next_weekday(d, weekday):
    days_ahead = weekday - d.weekday()
    if days_ahead <= 0:
        days_ahead += 7
    return d + datetime.timedelta(days_ahead)
 
 
currentDateTime = datetime.datetime.now()
date = currentDateTime.date()

# get next sunday starting from today
d = datetime.date(int(date.strftime("%Y")), int(date.strftime("%m")), int(date.strftime("%d")))
nextSunday = next_weekday(d, 6)
nextSunday = datetime.datetime.strptime(str(nextSunday), '%Y-%m-%d').date()
nextSundayStr = nextSunday.strftime('%b %d')

# get next saturday starting from the sunday (which will get that whole week)
d = datetime.date(int(nextSunday.strftime("%Y")), int(nextSunday.strftime("%m")), int(nextSunday.strftime("%d")))
nextSaturday = next_weekday(d, 5)
nextSaturday = datetime.datetime.strptime(str(nextSaturday), '%Y-%m-%d').date()
nextSaturdayStr = nextSaturday.strftime('%b %d')

# get the following sunday
d = datetime.date(int(nextSaturday.strftime("%Y")), int(nextSaturday.strftime("%m")), int(nextSaturday.strftime("%d")))
followingSunday = next_weekday(d, 6)
followingSunday = datetime.datetime.strptime(str(followingSunday), '%Y-%m-%d').date()
followingSundayStr = followingSunday.strftime('%b %d')

# get the following saturday
d = datetime.date(int(followingSunday.strftime("%Y")), int(followingSunday.strftime("%m")), int(followingSunday.strftime("%d")))
followingSaturday = next_weekday(d, 5)
followingSaturday = datetime.datetime.strptime(str(followingSaturday), '%Y-%m-%d').date()
followingSaturdayStr = followingSaturday.strftime('%b %d')

print("""
- Enter the following in order
| 0. Mentee Name
| 1. Mentor Name
| 2. Company 
| 3. Job Title
| 4. Educational Background
| 5. Additional Interests
| 6. Time availability
-
""")

print(""" 
{0},

Congratulations on your acceptance to the 1,000 Dreams Fund Mentorship Program! The mentorship is an incredible networking and learning opportunity for every mentee selected and we are excited to have you participate!

You have been matched with {1}. {1} works at {2} as a {3}. Below is their bio; please familiarize yourself with it and feel free to do your own research (LinkedIn is a great resource, but please do not make contact prior to your 1DF coordinated session).

Name: {1}
Current Role: {3}
Educational Background: {4}
Additional Interests: {5}
** Time Availability: {6}

This is an empowering opportunity that we cannot wait to commence, but before we do so, I have a couple of requests for you!

     Please provide me your timezone and availability for next week [{7}-{8}] and the week of [{9}- {10}].  I will work to finalize your session time ASAP!

     As a part of your participation, we need you to submit five (or more) thoughtful questions you would like to ask and discuss with your mentor.

Attached is our MentorHER Toolkit, which we created to provide advice on how to have an effective 60-minute MentorHER Session.

For now, that's all from us here at 1DF! Just remember to confirm your availability with me in the next 24 hours, and soon after you can expect a google invitation for the call. Until then, please let me know if you need anything!

Best,
Catherine Laserna
""".format(input(), input(), input(), input(), input(), input(), input(), nextSundayStr, nextSaturdayStr, followingSundayStr, followingSaturdayStr))