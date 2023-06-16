(
    @REM Build
    cmake -B build -A win32
    cmake --build build --config Release

    if exist "D:\Dev Project\Asa - Better GD\build\Release\asa-bettergd.dll" (
        move "D:\Dev Project\Asa - Better GD\build\Release\asa-bettergd.dll" "D:\Program Files\Steam\steamapps\common\Geometry Dash\extensions"
        if exist "D:\Dev Project\Asa - Better GD\build\Release\asa-bettergd.dll" (
            echo The file has not been moved yet
        ) else (
            cd "D:\Program Files\Steam\steamapps\common\Geometry Dash"
            start GeometryDash.exe
            echo Geometry Dash is ready :D
        )
    ) else (
        echo Oh no, you got an error
    )   
)