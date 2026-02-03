project('example', 'cpp')
# Source files
src = [
    'main.cpp'
]

# Qt5 dependencies
qt6_dep = [
    dependency('Qt6Core'),
    dependency('Qt6Gui'),
    dependency('Qt6Widgets'),
    dependency('Qt6WebEngineWidgets'),
]

# -fPIC required
add_project_arguments('-fPIC', language: 'cpp')

# executable file
executable('instagram-qt6', src, dependencies: qt6_dep, install: true)
install_data('instagram.desktop', install_dir : get_option('prefix') / 'share/applications/')
install_data('instagram-qt6.svg', install_dir : get_option('prefix') / 'share/icons/hicolor/scalable/apps/')