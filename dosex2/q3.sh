echo "Enter Internal Marks:"
read internal
echo "Enter Attendance Percentage:"
read attendance
echo "Enter External Marks:"
read external

failed=0

if [ $internal -lt 16 ]; then
    echo "Internal marks are insufficient."
    failed=1
fi

if [ $attendance -lt 40 ]; then
    echo "Attendance percentage is insufficient."
    failed=1
fi

if [ $external -lt 24 ]; then
    echo "External marks are insufficient."
    failed=1
fi

if [ $failed -eq 0 ]; then
    echo "Allowed for Next Semester."
fi
