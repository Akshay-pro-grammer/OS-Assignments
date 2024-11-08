echo "Enter the day number from 1 to 7 (1=Monday, 7=Sunday):"
read day
case $day in
    1)
        echo "Monday: No Class on Monday"
        ;;
    2)
        echo "Tuesday: DOS class time is 10:00-11:00, room number C104"
        ;;
    3)
        echo "Wednesday: No Class on Wednesday"
        ;;
    4)
        echo "Thursday: DOS class time is 15:00-16:00, room number C104"
        ;;
    5)
        echo "Friday: DOS class time is 14:00-16:00, room number C009"
        ;;
    6)
        echo "Saturday: DOS class time is 17:00-18:00, room number C104"
        ;;
    7)
        echo "Sunday: Holiday"
        ;;
    *)
        echo "Invalid input. Please enter a number from 1 to 7."
        ;;
esac

