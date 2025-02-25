#include <Windows.h>
#include <Shlwapi.h>
#include <tchar.h>
#include <string>

#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "shell32.lib")
#define RTL_MAX_DRIVE_LETTERS 32
#define GDI_HANDLE_BUFFER_SIZE32 34
#define GDI_HANDLE_BUFFER_SIZE64 60
#define GDI_BATCH_BUFFER_SIZE 310

#define NtCurrentProcess() ((HANDLE)(LONG_PTR)-1)
#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)
#endif

#if !defined(_M_X64)
#define GDI_HANDLE_BUFFER_SIZE GDI_HANDLE_BUFFER_SIZE32
#else
#define GDI_HANDLE_BUFFER_SIZE GDI_HANDLE_BUFFER_SIZE64
#endif

typedef ULONG GDI_HANDLE_BUFFER32[GDI_HANDLE_BUFFER_SIZE32];
typedef ULONG GDI_HANDLE_BUFFER64[GDI_HANDLE_BUFFER_SIZE64];
typedef ULONG GDI_HANDLE_BUFFER[GDI_HANDLE_BUFFER_SIZE];

typedef struct _UNICODE_STRING
{
        USHORT Length;
        USHORT MaximumLength;
        PWSTR Buffer;
} UNICODE_STRING;
typedef UNICODE_STRING *PUNICODE_STRING;

typedef struct _STRING
{
        USHORT Length;
        USHORT MaximumLength;
        PCHAR Buffer;
} STRING;
typedef STRING *PSTRING;

typedef struct _CLIENT_ID
{
        HANDLE UniqueProcess;
        HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef struct _CLIENT_ID64
{
        ULONG64 UniqueProcess;
        ULONG64 UniqueThread;
} CLIENT_ID64, *PCLIENT_ID64;

typedef struct _LDR_DATA_TABLE_ENTRY_COMPATIBLE
{
        LIST_ENTRY InLoadOrderLinks;
        LIST_ENTRY InMemoryOrderLinks;
        union
        {
                LIST_ENTRY InInitializationOrderLinks;
                LIST_ENTRY InProgressLinks;
        } DUMMYUNION0;
        PVOID DllBase;
        PVOID EntryPoint;
        ULONG SizeOfImage;
        UNICODE_STRING FullDllName;
        UNICODE_STRING BaseDllName;
        union
        {
                ULONG Flags;
                struct
                {
                        ULONG PackagedBinary : 1;                   // Size=4 Offset=104 BitOffset=0 BitCount=1
                        ULONG MarkedForRemoval : 1;                   // Size=4 Offset=104 BitOffset=1 BitCount=1
                        ULONG ImageDll : 1;                                   // Size=4 Offset=104 BitOffset=2 BitCount=1
                        ULONG LoadNotificationsSent : 1;   // Size=4 Offset=104 BitOffset=3 BitCount=1
                        ULONG TelemetryEntryProcessed : 1; // Size=4 Offset=104 BitOffset=4 BitCount=1
                        ULONG ProcessStaticImport : 1;           // Size=4 Offset=104 BitOffset=5 BitCount=1
                        ULONG InLegacyLists : 1;                   // Size=4 Offset=104 BitOffset=6 BitCount=1
                        ULONG InIndexes : 1;                           // Size=4 Offset=104 BitOffset=7 BitCount=1
                        ULONG ShimDll : 1;                                   // Size=4 Offset=104 BitOffset=8 BitCount=1
                        ULONG InExceptionTable : 1;                   // Size=4 Offset=104 BitOffset=9 BitCount=1
                        ULONG ReservedFlags1 : 2;                   // Size=4 Offset=104 BitOffset=10 BitCount=2
                        ULONG LoadInProgress : 1;                   // Size=4 Offset=104 BitOffset=12 BitCount=1
                        ULONG LoadConfigProcessed : 1;           // Size=4 Offset=104 BitOffset=13 BitCount=1
                        ULONG EntryProcessed : 1;                   // Size=4 Offset=104 BitOffset=14 BitCount=1
                        ULONG ProtectDelayLoad : 1;                   // Size=4 Offset=104 BitOffset=15 BitCount=1
                        ULONG ReservedFlags3 : 2;                   // Size=4 Offset=104 BitOffset=16 BitCount=2
                        ULONG DontCallForThreads : 1;           // Size=4 Offset=104 BitOffset=18 BitCount=1
                        ULONG ProcessAttachCalled : 1;           // Size=4 Offset=104 BitOffset=19 BitCount=1
                        ULONG ProcessAttachFailed : 1;           // Size=4 Offset=104 BitOffset=20 BitCount=1
                        ULONG CorDeferredValidate : 1;           // Size=4 Offset=104 BitOffset=21 BitCount=1
                        ULONG CorImage : 1;                                   // Size=4 Offset=104 BitOffset=22 BitCount=1
                        ULONG DontRelocate : 1;                           // Size=4 Offset=104 BitOffset=23 BitCount=1
                        ULONG CorILOnly : 1;                           // Size=4 Offset=104 BitOffset=24 BitCount=1
                        ULONG ChpeImage : 1;                           // Size=4 Offset=104 BitOffset=25 BitCount=1
                        ULONG ReservedFlags5 : 2;                   // Size=4 Offset=104 BitOffset=26 BitCount=2
                        ULONG Redirected : 1;                           // Size=4 Offset=104 BitOffset=28 BitCount=1
                        ULONG ReservedFlags6 : 2;                   // Size=4 Offset=104 BitOffset=29 BitCount=2
                        ULONG CompatDatabaseProcessed : 1; // Size=4 Offset=104 BitOffset=31 BitCount=1
                };
        } ENTRYFLAGSUNION;
        WORD ObsoleteLoadCount;
        WORD TlsIndex;
        union
        {
                LIST_ENTRY HashLinks;
                struct
                {
                        PVOID SectionPointer;
                        ULONG CheckSum;
                };
        } DUMMYUNION1;
        union
        {
                ULONG TimeDateStamp;
                PVOID LoadedImports;
        } DUMMYUNION2;
        //fields below removed for compatibility
} LDR_DATA_TABLE_ENTRY_COMPATIBLE, *PLDR_DATA_TABLE_ENTRY_COMPATIBLE;
typedef LDR_DATA_TABLE_ENTRY_COMPATIBLE LDR_DATA_TABLE_ENTRY;

typedef LDR_DATA_TABLE_ENTRY *PCLDR_DATA_TABLE_ENTRY;

typedef struct _PEB_LDR_DATA
{
        ULONG Length;
        BOOLEAN Initialized;
        HANDLE SsHandle;
        LIST_ENTRY InLoadOrderModuleList;
        LIST_ENTRY InMemoryOrderModuleList;
        LIST_ENTRY InInitializationOrderModuleList;
        PVOID EntryInProgress;
        BOOLEAN ShutdownInProgress;
        HANDLE ShutdownThreadId;
} PEB_LDR_DATA, *PPEB_LDR_DATA;

typedef struct _CURDIR
{
        UNICODE_STRING DosPath;
        HANDLE Handle;
} CURDIR, *PCURDIR;

typedef struct _RTL_DRIVE_LETTER_CURDIR
{
        USHORT Flags;
        USHORT Length;
        ULONG TimeStamp;
        STRING DosPath;
} RTL_DRIVE_LETTER_CURDIR, *PRTL_DRIVE_LETTER_CURDIR;

typedef struct _RTL_USER_PROCESS_PARAMETERS
{
        ULONG MaximumLength;
        ULONG Length;

        ULONG Flags;
        ULONG DebugFlags;

        HANDLE ConsoleHandle;
        ULONG ConsoleFlags;
        HANDLE StandardInput;
        HANDLE StandardOutput;
        HANDLE StandardError;

        CURDIR CurrentDirectory;
        UNICODE_STRING DllPath;
        UNICODE_STRING ImagePathName;
        UNICODE_STRING CommandLine;
        PVOID Environment;

        ULONG StartingX;
        ULONG StartingY;
        ULONG CountX;
        ULONG CountY;
        ULONG CountCharsX;
        ULONG CountCharsY;
        ULONG FillAttribute;

        ULONG WindowFlags;
        ULONG ShowWindowFlags;
        UNICODE_STRING WindowTitle;
        UNICODE_STRING DesktopInfo;
        UNICODE_STRING ShellInfo;
        UNICODE_STRING RuntimeData;
        RTL_DRIVE_LETTER_CURDIR CurrentDirectories[RTL_MAX_DRIVE_LETTERS];

        ULONG EnvironmentSize;
        ULONG EnvironmentVersion;
        PVOID PackageDependencyData; //8+
        ULONG ProcessGroupId;
        // ULONG LoaderThreads;
} RTL_USER_PROCESS_PARAMETERS, *PRTL_USER_PROCESS_PARAMETERS;

typedef struct _PEB
{
        BOOLEAN InheritedAddressSpace;
        BOOLEAN ReadImageFileExecOptions;
        BOOLEAN BeingDebugged;
        union
        {
                BOOLEAN BitField;
                struct
                {
                        BOOLEAN ImageUsesLargePages : 1;
                        BOOLEAN IsProtectedProcess : 1;
                        BOOLEAN IsImageDynamicallyRelocated : 1;
                        BOOLEAN SkipPatchingUser32Forwarders : 1;
                        BOOLEAN IsPackagedProcess : 1;
                        BOOLEAN IsAppContainer : 1;
                        BOOLEAN IsProtectedProcessLight : 1;
                        BOOLEAN IsLongPathAwareProcess : 1;
                };
        };
        HANDLE Mutant;

        PVOID ImageBaseAddress;
        PPEB_LDR_DATA Ldr;
        PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
        PVOID SubSystemData;
        PVOID ProcessHeap;
        PRTL_CRITICAL_SECTION FastPebLock;
        PVOID AtlThunkSListPtr;
        PVOID IFEOKey;
        union
        {
                ULONG CrossProcessFlags;
                struct
                {
                        ULONG ProcessInJob : 1;
                        ULONG ProcessInitializing : 1;
                        ULONG ProcessUsingVEH : 1;
                        ULONG ProcessUsingVCH : 1;
                        ULONG ProcessUsingFTH : 1;
                        ULONG ProcessPreviouslyThrottled : 1;
                        ULONG ProcessCurrentlyThrottled : 1;
                        ULONG ReservedBits0 : 25;
                };
                ULONG EnvironmentUpdateCount;
        };
        union
        {
                PVOID KernelCallbackTable;
                PVOID UserSharedInfoPtr;
        };
        ULONG SystemReserved[1];
        ULONG AtlThunkSListPtr32;
        PVOID ApiSetMap;
        ULONG TlsExpansionCounter;
        PVOID TlsBitmap;
        ULONG TlsBitmapBits[2];
        PVOID ReadOnlySharedMemoryBase;
        PVOID HotpatchInformation;
        PVOID *ReadOnlyStaticServerData;
        PVOID AnsiCodePageData;
        PVOID OemCodePageData;
        PVOID UnicodeCaseTableData;

        ULONG NumberOfProcessors;
        ULONG NtGlobalFlag;

        LARGE_INTEGER CriticalSectionTimeout;
        SIZE_T HeapSegmentReserve;
        SIZE_T HeapSegmentCommit;
        SIZE_T HeapDeCommitTotalFreeThreshold;
        SIZE_T HeapDeCommitFreeBlockThreshold;

        ULONG NumberOfHeaps;
        ULONG MaximumNumberOfHeaps;
        PVOID *ProcessHeaps;

        PVOID GdiSharedHandleTable;
        PVOID ProcessStarterHelper;
        ULONG GdiDCAttributeList;

        PRTL_CRITICAL_SECTION LoaderLock;

        ULONG OSMajorVersion;
        ULONG OSMinorVersion;
        USHORT OSBuildNumber;
        USHORT OSCSDVersion;
        ULONG OSPlatformId;
        ULONG ImageSubsystem;
        ULONG ImageSubsystemMajorVersion;
        ULONG ImageSubsystemMinorVersion;
        ULONG_PTR ImageProcessAffinityMask;
        GDI_HANDLE_BUFFER GdiHandleBuffer;
        PVOID PostProcessInitRoutine;

        PVOID TlsExpansionBitmap;
        ULONG TlsExpansionBitmapBits[32];

        ULONG SessionId;

        ULARGE_INTEGER AppCompatFlags;
        ULARGE_INTEGER AppCompatFlagsUser;
        PVOID pShimData;
        PVOID AppCompatInfo;

        UNICODE_STRING CSDVersion;

        PVOID ActivationContextData;
        PVOID ProcessAssemblyStorageMap;
        PVOID SystemDefaultActivationContextData;
        PVOID SystemAssemblyStorageMap;

        SIZE_T MinimumStackCommit;

        PVOID *FlsCallback;
        LIST_ENTRY FlsListHead;
        PVOID FlsBitmap;
        ULONG FlsBitmapBits[FLS_MAXIMUM_AVAILABLE / (sizeof(ULONG) * 8)];
        ULONG FlsHighIndex;

        PVOID WerRegistrationData;
        PVOID WerShipAssertPtr;
        PVOID pContextData;
        PVOID pImageHeaderHash;
        union
        {
                ULONG TracingFlags;
                struct
                {
                        ULONG HeapTracingEnabled : 1;
                        ULONG CritSecTracingEnabled : 1;
                        ULONG LibLoaderTracingEnabled : 1;
                        ULONG SpareTracingBits : 29;
                };
        };
        ULONGLONG CsrServerReadOnlySharedMemoryBase;
} PEB, *PPEB;

typedef struct _GDI_TEB_BATCH
{
        ULONG Offset;
        UCHAR Alignment[4];
        ULONG_PTR HDC;
        ULONG Buffer[GDI_BATCH_BUFFER_SIZE];
} GDI_TEB_BATCH, *PGDI_TEB_BATCH;

typedef struct _TEB_ACTIVE_FRAME_CONTEXT
{
        ULONG Flags;
        PSTR FrameName;
} TEB_ACTIVE_FRAME_CONTEXT, *PTEB_ACTIVE_FRAME_CONTEXT;

typedef struct _TEB_ACTIVE_FRAME
{
        ULONG Flags;
        struct _TEB_ACTIVE_FRAME *Previous;
        PTEB_ACTIVE_FRAME_CONTEXT Context;
} TEB_ACTIVE_FRAME, *PTEB_ACTIVE_FRAME;

typedef struct _TEB
{
        NT_TIB NtTib;

        PVOID EnvironmentPointer;
        CLIENT_ID ClientId;
        PVOID ActiveRpcHandle;
        PVOID ThreadLocalStoragePointer;
        PPEB ProcessEnvironmentBlock;

        ULONG LastErrorValue;
        ULONG CountOfOwnedCriticalSections;
        PVOID CsrClientThread;
        PVOID Win32ThreadInfo;
        ULONG User32Reserved[26];
        ULONG UserReserved[5];
        PVOID WOW32Reserved;
        LCID CurrentLocale;
        ULONG FpSoftwareStatusRegister;
        PVOID SystemReserved1[54];
        NTSTATUS ExceptionCode;
        PVOID ActivationContextStackPointer;
#if defined(_M_X64)
        UCHAR SpareBytes[24];
#else
        UCHAR SpareBytes[36];
#endif
        ULONG TxFsContext;

        GDI_TEB_BATCH GdiTebBatch;
        CLIENT_ID RealClientId;
        HANDLE GdiCachedProcessHandle;
        ULONG GdiClientPID;
        ULONG GdiClientTID;
        PVOID GdiThreadLocalInfo;
        ULONG_PTR Win32ClientInfo[62];
        PVOID glDispatchTable[233];
        ULONG_PTR glReserved1[29];
        PVOID glReserved2;
        PVOID glSectionInfo;
        PVOID glSection;
        PVOID glTable;
        PVOID glCurrentRC;
        PVOID glContext;

        NTSTATUS LastStatusValue;
        UNICODE_STRING StaticUnicodeString;
        WCHAR StaticUnicodeBuffer[261];

        PVOID DeallocationStack;
        PVOID TlsSlots[64];
        LIST_ENTRY TlsLinks;

        PVOID Vdm;
        PVOID ReservedForNtRpc;
        PVOID DbgSsReserved[2];

        ULONG HardErrorMode;
#if defined(_M_X64)
        PVOID Instrumentation[11];
#else
        PVOID Instrumentation[9];
#endif
        GUID ActivityId;

        PVOID SubProcessTag;
        PVOID EtwLocalData;
        PVOID EtwTraceData;
        PVOID WinSockData;
        ULONG GdiBatchCount;

        union
        {
                PROCESSOR_NUMBER CurrentIdealProcessor;
                ULONG IdealProcessorValue;
                struct
                {
                        UCHAR ReservedPad0;
                        UCHAR ReservedPad1;
                        UCHAR ReservedPad2;
                        UCHAR IdealProcessor;
                };
        };

        ULONG GuaranteedStackBytes;
        PVOID ReservedForPerf;
        PVOID ReservedForOle;
        ULONG WaitingOnLoaderLock;
        PVOID SavedPriorityState;
        ULONG_PTR SoftPatchPtr1;
        PVOID ThreadPoolData;
        PVOID *TlsExpansionSlots;
#if defined(_M_X64)
        PVOID DeallocationBStore;
        PVOID BStoreLimit;
#endif
        ULONG MuiGeneration;
        ULONG IsImpersonating;
        PVOID NlsCache;
        PVOID pShimData;
        ULONG HeapVirtualAffinity;
        HANDLE CurrentTransactionHandle;
        PTEB_ACTIVE_FRAME ActiveFrame;
        PVOID FlsData;

        PVOID PreferredLanguages;
        PVOID UserPrefLanguages;
        PVOID MergedPrefLanguages;
        ULONG MuiImpersonation;

        union
        {
                USHORT CrossTebFlags;
                USHORT SpareCrossTebBits : 16;
        };
        union
        {
                USHORT SameTebFlags;
                struct
                {
                        USHORT SafeThunkCall : 1;
                        USHORT InDebugPrint : 1;
                        USHORT HasFiberData : 1;
                        USHORT SkipThreadAttach : 1;
                        USHORT WerInShipAssertCode : 1;
                        USHORT RanProcessInit : 1;
                        USHORT ClonedThread : 1;
                        USHORT SuppressDebugMsg : 1;
                        USHORT DisableUserStackWalk : 1;
                        USHORT RtlExceptionAttached : 1;
                        USHORT InitialThread : 1;
                        USHORT SpareSameTebBits : 1;
                };
        };

        PVOID TxnScopeEnterCallback;
        PVOID TxnScopeExitCallback;
        PVOID TxnScopeContext;
        ULONG LockCount;
        ULONG SpareUlong0;
        PVOID ResourceRetValue;
} TEB, *PTEB;

typedef VOID(NTAPI *PLDR_LOADED_MODULE_ENUMERATION_CALLBACK_FUNCTION)(
        _In_ PCLDR_DATA_TABLE_ENTRY DataTableEntry,
        _In_ PVOID Context,
        _Inout_ BOOLEAN *StopEnumeration);

typedef PVOID NTAPI RTLINITUNICODESTRING(
        _Inout_ PUNICODE_STRING DestinationString,
        _In_opt_ PCWSTR SourceString);
typedef RTLINITUNICODESTRING FAR *LPRTLINITUNICODESTRING;
LPRTLINITUNICODESTRING RtlInitUnicodeString;

typedef NTSTATUS NTAPI RTLENTERCRITICALSECTION(
        _In_ PRTL_CRITICAL_SECTION CriticalSection);
typedef RTLENTERCRITICALSECTION FAR *LPRTLENTERCRITICALSECTION;
LPRTLENTERCRITICALSECTION RtlEnterCriticalSection;

typedef NTSTATUS NTAPI RTLLEAVECRITICALSECTION(
        _In_ PRTL_CRITICAL_SECTION CriticalSection);
typedef RTLLEAVECRITICALSECTION FAR *LPRTLLEAVECRITICALSECTION;
LPRTLLEAVECRITICALSECTION RtlLeaveCriticalSection;

typedef NTSTATUS NTAPI LDRENUMERATELOADEDMODULES(
        _In_opt_ ULONG Flags,
        _In_ PLDR_LOADED_MODULE_ENUMERATION_CALLBACK_FUNCTION CallbackFunction,
        _In_opt_ PVOID Context);
typedef LDRENUMERATELOADEDMODULES FAR *LPLDRENUMERATELOADEDMODULES;
LPLDRENUMERATELOADEDMODULES LdrEnumerateLoadedModules;

typedef NTSTATUS NTAPI NTALLOCATEVIRTUALMEMORY(
        _In_ HANDLE ProcessHandle,
        _Inout_ PVOID *BaseAddress,
        _In_ ULONG_PTR ZeroBits,
        _Inout_ PSIZE_T RegionSize,
        _In_ ULONG AllocationType,
        _In_ ULONG Protect);
typedef NTALLOCATEVIRTUALMEMORY FAR *LPNTALLOCATEVIRTUALMEMORY;
LPNTALLOCATEVIRTUALMEMORY NtAllocateVirtualMemory;

__inline struct _PEB *NtCurrentPeb() { return NtCurrentTeb()->ProcessEnvironmentBlock; }

VOID PEBFake(LPCWSTR pFullDllName, LPCWSTR pBaseDllName)
{
        NTSTATUS Status;
        PPEB Peb = NtCurrentPeb();
        WCHAR CurrentDir[MAX_PATH] = {0};

        StrCpyW(CurrentDir, pFullDllName);

        PathAppendW(CurrentDir, L"..");
        wprintf(L"\nCurrentDir = %s\n", CurrentDir);

        RtlEnterCriticalSection(Peb->FastPebLock);

        // find process imagepath
        RtlInitUnicodeString(&Peb->ProcessParameters->ImagePathName, pFullDllName);
        //wprintf(L"%s\n", Peb->ProcessParameters->ImagePathName.Buffer );
        RtlInitUnicodeString(&Peb->ProcessParameters->CommandLine, pFullDllName);
        RtlInitUnicodeString(&Peb->ProcessParameters->CurrentDirectory.DosPath, CurrentDir);

        // enum ldr
        LIST_ENTRY *ListHead, *Current;
        ListHead = &(Peb->Ldr->InLoadOrderModuleList);
        Current = ListHead->Flink;
        PCLDR_DATA_TABLE_ENTRY pstEntry;
        while (Current != ListHead)
        {
                pstEntry = CONTAINING_RECORD(Current, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);

                // printf("find it %x %x \n", pstEntry->DllBase, Peb->ImageBaseAddress);

                if (pstEntry->DllBase == Peb->ImageBaseAddress)
                {
                        // 修改进程模块 映像路径 + 名称
                        // fix image path and name
                        RtlInitUnicodeString(&pstEntry->FullDllName, pFullDllName);
                        RtlInitUnicodeString(&pstEntry->BaseDllName, pBaseDllName);

                        break;
                }
                Current = pstEntry->InLoadOrderLinks.Flink;
        }

        RtlLeaveCriticalSection(Peb->FastPebLock);
}

HRESULT AnsiToUnicode(LPCSTR pszA, LPOLESTR *ppszW)
{
        ULONG cCharacters;
        DWORD dwError;
        if (NULL == pszA)
        {
                *ppszW = NULL;
                return NOERROR;
        }
        cCharacters = strlen(pszA) + 1;
        *ppszW = (LPOLESTR)malloc(cCharacters * 2);
        if (NULL == *ppszW)
                return E_OUTOFMEMORY;
        if (0 == MultiByteToWideChar(CP_ACP, 0, pszA, cCharacters,
                                                                 *ppszW, cCharacters))
        {
                dwError = GetLastError();
                free(*ppszW);
                *ppszW = NULL;
                return HRESULT_FROM_WIN32(dwError);
        }
        return NOERROR;
}

bool init()
{
        bool bInit = false;
        do
        {

                HINSTANCE hinstStub = GetModuleHandleW(L"ntdll.dll");
                if (hinstStub)
                {
                        RtlInitUnicodeString = (LPRTLINITUNICODESTRING)GetProcAddress(hinstStub, "RtlInitUnicodeString");
                        if (!RtlInitUnicodeString)
                        {
                                printf("Could not find RtlInitUnicodeString entry point in NTDLL.DLL");
                                break;
                        }

                        RtlEnterCriticalSection = (LPRTLENTERCRITICALSECTION)GetProcAddress(hinstStub, "RtlEnterCriticalSection");
                        if (!RtlEnterCriticalSection)
                        {
                                printf("Could not find RtlEnterCriticalSection entry point in NTDLL.DLL");
                                break;
                        }

                        RtlLeaveCriticalSection = (LPRTLLEAVECRITICALSECTION)GetProcAddress(hinstStub, "RtlLeaveCriticalSection");
                        if (!RtlLeaveCriticalSection)
                        {
                                printf("Could not find RtlLeaveCriticalSection entry point in NTDLL.DLL");
                                break;
                        }

                        LdrEnumerateLoadedModules = (LPLDRENUMERATELOADEDMODULES)GetProcAddress(hinstStub, "LdrEnumerateLoadedModules");
                        if (!LdrEnumerateLoadedModules)
                        {
                                printf("Could not find LdrEnumerateLoadedModules entry point in NTDLL.DLL");
                                break;
                        }

                        NtAllocateVirtualMemory = (LPNTALLOCATEVIRTUALMEMORY)GetProcAddress(hinstStub, "NtAllocateVirtualMemory");
                        if (!NtAllocateVirtualMemory)
                        {
                                printf("Could not find NtAllocateVirtualMemory entry point in NTDLL.DLL");
                                break;
                        }
                }
                else
                {
                        printf("Could not GetModuleHandle of NTDLL.DLL");
                        break;
                }

                bInit = true;

        } while (0);

        return bInit;
}

int main(int, char **)
{

        if (init())
        {
                LPCWSTR myPath = _T(R"(C:\Windows\SysWOW64\calc.exe)");
                LPCWSTR myName = _T("calc.exe");

                printf("my PID = %d", GetCurrentProcessId());

                PEBFake(myPath, myName);

                // check
                while (1)
                {
                        Sleep(10000);
                }
        }

        return 0;
}
