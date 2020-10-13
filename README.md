# Breakdown Spotify playlists based on artist genre or mood

## Basic workflow summary

1. User logs in to Spotify.
2. Display all playlists they have.
3. User selects one playlist.
4. Ask if the user wants to break it down by: 
	* Artist genre - get genres from song artist
	* Mood of the song - get track analysis from Spotify Web API, need to figure out if we can allow user to tune this categorization
5. Show suggested breakdown into multiple lists.
6. User can stream songs directly from those lists in the app (needed?).
7. User can rename the broken down lists.
8. User can persist each of those lists in their Spotify profile. 
9. User can go back to selecting playlists and breaking them down (point 2).

## Platform

Windows 10

## Technologies

1. `UWP`
2. `C++/WinRT`

## Building

You would need the following things to build the solution and view the application:

1. Visual Studio 2019 with the UWP workload (make sure to check the C++ (v14x) Universal Windows Platform tools option) (https://visualstudio.microsoft.com/vs/)
2. C++/WinRT VSIX (https://docs.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt#visual-studio-support-for-cwinrt-xaml-the-vsix-extension-and-the-nuget-package)
3. `vcpkg` (https://github.com/microsoft/vcpkg#quick-start)
4. `x64-uwp` triplet of `nlohmann-json` via `vcpkg` (https://github.com/nlohmann/json):

    ```ps1
	.\vcpkg.exe install nlohmann-json:x64-uwp
	```
5. Clone this repository and build `spotify-breakdown-playlists-cppwinrt.sln`.
6. Add a file inside the project directory called `SpotifyClientId.h` which contains the Spotify Developer Client ID like so:

    ```cpp
    #pragma once

    namespace winrt::spotify_breakdown_playlists_cppwinrt
    {
        namespace spotify_app_info
	    {
	        const std::wstring client_id = L"...";
	    }
    }
    ```
