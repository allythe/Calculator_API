import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        consoleApplication: true

        cpp.cxxLanguageVersion: "c++17"

        property path graph_lib_dir: "../Graph_lib"

        files: [

            "logic.cpp",
            "logic.h",
            "main.cpp",
            "token.cpp",
            "token.h",
            "variable.cpp",
            "variable.h",
            "grid.cpp",
            "grid.h",
            "buttons.cpp",
            "buttons.h",


            graph_lib_dir +"/Graph.cpp",
            graph_lib_dir +"/GUI.cpp",
            graph_lib_dir +"/Window.cpp",
        ]

        cpp.systemIncludePaths: "../fltk_win64/include"
        cpp.libraryPaths: "../fltk_win64/lib"

        cpp.driverLinkerFlags: "-mwindows"
        cpp.staticLibraries: [
            "fltk_images",
            "fltk",
            "fltk_png",
            "z",
            "fltk_jpeg",
            "ole32",
            "uuid",
            "comctl32",
        ]


    }
}
