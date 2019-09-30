# Breakdown Spotify playlists based on artist genre or mood

## Workflow summary

1. User logs in to Spotify.
2. Display all playlists they have.
3. User selects one playlist.
4. Ask if the user wants to break it down by: 
	a. Artist genre - get genres from song artist
	b. Mood of the song - get track analysis from Spotify Web API, need to figure out if we can allow user to tune this categorization
5. Show suggested breakdown into multiple lists.
6. User can stream songs directly from those lists in the app (needed?).
7. User can rename the broken down lists.
8. User can persist each of those lists in their Spotify profile. 
9. User can go back to selecting playlists and breaking them down (point 2).

## Platform

Windows 10 UWP

## Technologies

1. `cpprestsdk`
2. `C++/WinRT`
3. `XAML`