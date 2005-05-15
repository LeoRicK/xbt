#if !defined(AFX_XBTCLIENTDLG_H__24B01140_CC8B_4862_B4FD_31A9CF22FAF8__INCLUDED_)
#define AFX_XBTCLIENTDLG_H__24B01140_CC8B_4862_B4FD_31A9CF22FAF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../bt test/server.h"
#include "ListCtrlEx1.h"
#include "dns_worker.h"
#include "resource.h"
#include "stream_reader.h"

class CXBTClientDlg: public ETSLayoutDialog
{
public:
	bool get_profile_hide_on_deactivate();
	bool get_profile_lower_process_priority();
	bool get_profile_show_advanced_columns();
	bool get_profile_show_confirm_exit_dialog();
	bool get_profile_show_tray_icon();
	bool get_profile_start_minimized();
	bool get_profile_upnp();
	int get_profile_upload_rate();
	string get_profile_user_agent();
	void write_profile_hide_on_deactivate(bool);
	void write_profile_lower_process_priority(bool);
	void write_profile_show_advanced_columns(bool);
	void write_profile_show_confirm_exit_dialog(bool);
	void write_profile_show_tray_icon(bool v);
	void write_profile_start_minimized(bool);
	void write_profile_upnp(bool);
	void write_profile_upload_rate(int);
	void write_profile_user_agent(const string&);
	int GetProfileInt(LPCTSTR Entry, int Default = 0);
	string GetProfileString(LPCTSTR Entry, LPCTSTR Default = "");
	BOOL WriteProfileInt(LPCTSTR Entry, int Value);
	BOOL WriteProfileString(LPCTSTR Entry, const string& Value);
	void register_hot_key(DWORD v);
	void unregister_hot_key();
	void update_global_details();
	void set_torrent_state(Cbt_file::t_state);
	Cbt_file::t_state get_torrent_state();
	void set_bottom_view(int v);
	int get_priority();
	void set_priority(int v);
	int get_torrent_priority();
	void set_torrent_priority(int v);
	void set_clipboard(const string&);
	void lower_process_priority(bool);
	void set_dir(const string& completes, const string& incompletes, const string local_app_data, const string& torrents);
	void insert_columns(bool auto_size);
	void insert_top_columns();
	void insert_bottom_columns();
	void sort_peers();
	void sort_files();
	int events_compare(int id_a, int id_b) const;
	int files_compare(int id_a, int id_b) const;
	int global_events_compare(int id_a, int id_b) const;
	int peers_compare(int id_a, int id_b) const;
	int pieces_compare(int id_a, int id_b) const;
	int sub_files_compare(int id_a, int id_b) const;
	static unsigned int server_thread(void* p);
	void start_server();
	void stop_server();
	void register_tray();
	void unregister_tray();
	void update_tray();
	void update_tray(const char* info_title, const char* info);
	void fill_peers();
	void open(const string& name, bool ask_for_location);
	void open_url(const string&);
	CXBTClientDlg(CWnd* pParent = NULL);

	//{{AFX_DATA(CXBTClientDlg)
	enum { IDD = IDD_XBTCLIENT_DIALOG };
	CTabCtrl	m_tab;
	CListCtrlEx1	m_peers;
	CListCtrlEx1	m_files;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CXBTClientDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

protected:
	afx_msg long OnAreYouMe(WPARAM, LPARAM);
	afx_msg long OnTaskbarCreated(WPARAM, LPARAM);
	afx_msg long OnTray(WPARAM, LPARAM);
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	void OnTrayMenu();
	afx_msg void OnCustomdrawFiles(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCustomdrawPeers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg long OnHotKey(WPARAM, LPARAM);
	HACCEL m_hAccel;
	HICON m_hIcon;

	//{{AFX_MSG(CXBTClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetdispinfoFiles(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnGetdispinfoPeers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedFiles(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnPopupExplore();
	afx_msg void OnDestroy();
	afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnEndSession(BOOL bEnding);
	afx_msg void OnColumnclickFiles(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclickPeers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkFiles(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPopupAnnounce();
	afx_msg void OnPopupExploreTracker();
	afx_msg void OnPopupViewDetails();
	afx_msg void OnPopupViewFiles();
	afx_msg void OnPopupViewPeers();
	afx_msg void OnPopupViewTrackers();
	afx_msg void OnPopupViewEvents();
	afx_msg void OnPopupPriorityExclude();
	afx_msg void OnPopupPriorityHigh();
	afx_msg void OnPopupPriorityLow();
	afx_msg void OnPopupPriorityNormal();
	afx_msg void OnPopupViewAdvancedColumns();
	afx_msg void OnPopupViewTrayIcon();
	afx_msg void OnDblclkPeers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnUpdatePopupViewAdvancedColumns(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupViewTrayIcon(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupViewDetails(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupViewEvents(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupViewFiles(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupViewPeers(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupViewTrackers(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupAnnounce(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupExploreTracker(CCmdUI* pCmdUI);
	afx_msg void OnPopupUploadRateLimit();
	afx_msg void OnUpdatePopupUploadRateLimit(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupPriorityExclude(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupPriorityHigh(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupPriorityLow(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupPriorityNormal(CCmdUI* pCmdUI);
	afx_msg void OnPopupTorrentPriorityHigh();
	afx_msg void OnUpdatePopupTorrentPriorityHigh(CCmdUI* pCmdUI);
	afx_msg void OnPopupTorrentPriorityLow();
	afx_msg void OnUpdatePopupTorrentPriorityLow(CCmdUI* pCmdUI);
	afx_msg void OnPopupTorrentPriorityNormal();
	afx_msg void OnUpdatePopupTorrentPriorityNormal(CCmdUI* pCmdUI);
	afx_msg void OnPopupViewPieces();
	afx_msg void OnUpdatePopupViewPieces(CCmdUI* pCmdUI);
	afx_msg void OnPopupStatePaused();
	afx_msg void OnUpdatePopupStatePaused(CCmdUI* pCmdUI);
	afx_msg void OnPopupStateQueued();
	afx_msg void OnUpdatePopupStateQueued(CCmdUI* pCmdUI);
	afx_msg void OnPopupStateStarted();
	afx_msg void OnUpdatePopupStateStarted(CCmdUI* pCmdUI);
	afx_msg void OnPopupStateStopped();
	afx_msg void OnUpdatePopupStateStopped(CCmdUI* pCmdUI);
	afx_msg void OnPopupTorrentOptions();
	afx_msg void OnUpdatePopupTorrentOptions(CCmdUI* pCmdUI);
	virtual void OnCancel();
	afx_msg void OnActivateApp(BOOL bActive, HTASK hTask);
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnFileOpen();
	afx_msg void OnFileClose();
	afx_msg void OnUpdateFileClose(CCmdUI* pCmdUI);
	afx_msg void OnEditCopyAnnounceUrl();
	afx_msg void OnUpdateEditCopyAnnounceUrl(CCmdUI* pCmdUI);
	afx_msg void OnEditCopyHash();
	afx_msg void OnUpdateEditCopyHash(CCmdUI* pCmdUI);
	afx_msg void OnEditCopyUrl();
	afx_msg void OnUpdateEditCopyUrl(CCmdUI* pCmdUI);
	afx_msg void OnEditPasteUrl();
	afx_msg void OnFileNew();
	afx_msg void OnEditSelectAll();
	afx_msg void OnToolsOptions();
	afx_msg void OnToolsProfiles();
	afx_msg void OnToolsScheduler();
	afx_msg void OnToolsTrackers();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFileDelete();
	afx_msg void OnUpdateFileDelete(CCmdUI* pCmdUI);
	afx_msg void OnHelpHomePage();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg void OnPopupViewGlobalEvents();
	afx_msg void OnUpdatePopupViewGlobalEvents(CCmdUI* pCmdUI);
	afx_msg void OnPopupViewGlobalDetails();
	afx_msg void OnUpdatePopupViewGlobalDetails(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePopupExplore(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg void OnGetdispinfoDetails(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnGetdispinfoEvents(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnGetdispinfoGlobalDetails(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnGetdispinfoGlobalEvents(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnGetdispinfoPieces(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnGetdispinfoSubFiles(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnGetdispinfoTrackers(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
private:
	struct t_event
	{
		time_t time;
		int level;
		string message;
		string source;
	};

	struct t_peer: public Cbt_peer_data
	{
		in_addr m_host;
		int m_port;
		int m_down_rate;
		int m_up_rate;
		int mc_local_requests;
		int mc_remote_requests;
		int mc_pieces;
		int m_rtime;
		int m_stime;
		string m_debug;
		string m_host_name;
		bool m_removed;
	};

	struct t_piece: public Cbt_piece_data
	{
		int c_chunks_invalid;
		int c_chunks_valid;
		int c_peers;
		int index;
		int rank;
	};

	struct t_sub_file: public Cbt_sub_file_data
	{
	};

	struct t_tracker
	{
		string url;
	};

	typedef vector<t_event> t_events;
	typedef map<int, t_peer> t_peers;
	typedef vector<t_piece> t_pieces;
	typedef vector<t_sub_file> t_sub_files;
	typedef vector<t_tracker> t_trackers;

	struct t_file: public Cbt_file_data
	{
		string m_display_name;
		t_events events;
		t_trackers m_trackers;
		t_peers peers;
		t_pieces pieces;
		t_sub_files m_sub_files;
		int m_down_rate;
		int m_up_rate;
		int mc_distributed_copies;
		int mc_distributed_copies_remainder;
		int mc_leechers;
		int mc_seeders;
		int mc_invalid_chunks;
		int mc_invalid_pieces;
		int mc_valid_chunks;
		int mc_valid_pieces;
		int mcb_chunk;
		bool m_removed;
	};

	struct t_global_details
	{
		__int64 m_downloaded;
		__int64 m_downloaded_total;
		__int64 m_left;
		__int64 m_size;
		__int64 m_uploaded;
		__int64 m_uploaded_total;
		int m_down_rate;
		int m_start_time;
		int m_up_rate;
		int mc_files;
		int mc_leechers;
		int mc_seeders;
		int mc_torrents_complete;
		int mc_torrents_incomplete;
	};

	typedef vector<int> t_columns;
	typedef map<int, t_file> t_files;

	void read_peer_dump(t_file& f, Cstream_reader& sr);
	void read_file_dump(Cstream_reader& sr);
	void read_server_dump(Cstream_reader& sr);

	bool m_ask_for_location;
	bool m_hide_on_deactivate;
	bool m_initial_hide;
	t_columns m_torrents_columns;
	t_columns m_peers_columns;
	t_events m_events;
	t_file* m_file;
	t_files m_files_map;
	t_global_details m_global_details;
	Cdns_worker m_dns_worker;
	CString m_reg_key;
	Cserver m_server;
	CWinThread* m_server_thread;
	int m_bottom_view;
	int m_events_sort_column;
	int m_files_sort_column;
	int m_global_events_sort_column;
	int m_peers_sort_column;
	int m_pieces_sort_column;
	int m_torrents_sort_column;
	bool m_events_sort_reverse;
	bool m_files_sort_reverse;
	bool m_global_events_sort_reverse;
	bool m_peers_sort_reverse;
	bool m_pieces_sort_reverse;
	bool m_torrents_sort_reverse;
	bool m_show_advanced_columns;
	bool m_show_tray_icon;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XBTCLIENTDLG_H__24B01140_CC8B_4862_B4FD_31A9CF22FAF8__INCLUDED_)
