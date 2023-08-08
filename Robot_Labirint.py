from robot import RobotControl

rc = RobotControl()

l = rc.get_laser(360)
for _ in iter(int, 1):
    while l > 1:
        rc.move_straight()
        l = rc.get_laser(360)
        print (l)    
    rc.stop_robot()

    left = rc.get_laser(0)
    right = rc.get_laser(719)

    n = 0

    while n < 1:
        if left > right:
            rc.rotate(90)
            break
        else:
            rc.rotate(-90)
            break

    l = rc.get_laser(360)
    pass