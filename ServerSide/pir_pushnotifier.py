import urllib2
import json
import RPi.GPIO as GPIO
import time
import requests
import mechanize


GPIO.setmode(GPIO.BCM)

# In BCM mode pin 7 is identified by id 4
PIR_PIN = 4
GPIO.setup(PIR_PIN, GPIO.IN)

try:
        print "Reading PIR status"

        while True:
                if GPIO.input(PIR_PIN):
                        print "Motion detected"
                	sendNotification()
                        pushNotification()
                
                else:
                	print "No Intruder"
                time.sleep(2)
except KeyboardInterrupt:
        print "Exit"
        GPIO.cleanup()





