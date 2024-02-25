extends Node 

func play_music():
	var resume_pos = GlobalAudio.get_meta("pos")
	print("resuming at pos" + str(resume_pos))
	GlobalAudio.play(resume_pos)

func pause_music():
	var playback_pos = GlobalAudio.get_playback_position()
	print("stopping playback at: " + str(playback_pos))
	GlobalAudio.stop()
	GlobalAudio.set_meta("pos", playback_pos)
