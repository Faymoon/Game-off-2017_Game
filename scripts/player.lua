print("hello")

function player_update(delta, player)
    if Keyboard.IsKeyPressed(Keyboard.Down) then
        print("down")
    else if Keyboard.IsKeyPressed(Keyboard.Up) then
        print("up")
    else if Keyboard.IsKeyPressed(Keyboard.Right) then
        print("right")
    else if Keyboard.IsKeyPressed(Keyboard.Left) then
        print("left")
    end
end
